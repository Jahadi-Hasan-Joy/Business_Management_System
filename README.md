#include <bits/stdc++.h>
using namespace std;

class BusinessManagement
{
private:
    struct Product
    {
        string name;
        double buy_price;
        double sell_price;
    };

    vector<Product> products;
    const string filename = "data.txt";
    const string password = "123";

    void loadProducts()
    {
        products.clear();
        ifstream file(filename);
        if (!file)
            return;

        Product p;
        while (getline(file, p.name) && file >> p.buy_price >> p.sell_price)
        {
            file.ignore();
            products.push_back(p);
        }
        file.close();
    }

    void saveProducts()
    {
        ofstream file(filename, ios::trunc);
        for (const auto &p : products)
        {
            file << p.name << '\n'
                 << p.buy_price << '\n'
                 << p.sell_price << '\n';
        }
        file.close();
    }

public:
    BusinessManagement()
    {
        loadProducts();
    }

    void mainMenu();
    void addProduct();
    void showProducts();
    void searchProduct();
    void editProduct();
    void deleteProduct();
};

void BusinessManagement::mainMenu()
{
    while (true)
    {
        cout << "\n1. Add Product\n2. Show Products\n3. Search Product\n4. Edit Product\n5. Delete Product\n6. Log Out\nEnter choice: ";
        int choice;
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            addProduct();
            break;
        case 2:
            showProducts();
            break;
        case 3:
            searchProduct();
            break;
        case 4:
            editProduct();
            break;
        case 5:
            deleteProduct();
            break;
        case 6:
            cout << "Logging out...\n";
            return;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
}

void BusinessManagement::addProduct()
{
    int count;
    cout << "How many products do you want to add? ";
    cin >> count;
    cin.ignore();

    for (int i = 0; i < count; i++)
    {
        Product p;
        cout << "Enter product name: ";
        getline(cin, p.name);
        cout << "Enter buy price: ";
        cin >> p.buy_price;
        cout << "Enter sell price: ";
        cin >> p.sell_price;
        cin.ignore();
        products.push_back(p);
    }
    saveProducts();
}

void BusinessManagement::showProducts()
{
    if (products.empty())
    {
        cout << "No products available.\n";
        return;
    }
    for (size_t i = 0; i < products.size(); i++)
    {
        cout << "\nProduct " << i + 1 << "\nName: " << products[i].name
             << "\nBuy Price: " << products[i].buy_price
             << "\nSell Price: " << products[i].sell_price << "\n";
    }
}

void BusinessManagement::searchProduct()
{
    cout << "Enter product name to search: ";
    string name;
    getline(cin, name);

    for (const auto &p : products)
    {
        if (p.name == name)
        {
            cout << "\nName: " << p.name << "\nBuy Price: " << p.buy_price
                 << "\nSell Price: " << p.sell_price << "\n";
            return;
        }
    }
    cout << "Product not found.\n";
}

void BusinessManagement::editProduct()
{
    cout << "Enter product name to edit: ";
    string name;
    getline(cin, name);

    for (auto &p : products)
    {
        if (p.name == name)
        {
            cout << "\nCurrent Data:\nBuy Price: " << p.buy_price << "\nSell Price: " << p.sell_price << "\n";
            cout << "Enter new buy price: ";
            cin >> p.buy_price;
            cout << "Enter new sell price: ";
            cin >> p.sell_price;
            cin.ignore();
            saveProducts();
            return;
        }
    }
    cout << "Product not found.\n";
}

void BusinessManagement::deleteProduct()
{
    cout << "1. Delete all products\n2. Delete specific product\nEnter choice: ";
    int choice;
    cin >> choice;
    cin.ignore();

    if (choice == 1)
    {
        products.clear();
        saveProducts();
        cout << "All products deleted.\n";
    }
    else if (choice == 2)
    {
        cout << "Enter product name to delete: ";
        string name;
        getline(cin, name);

        auto it = remove_if(products.begin(), products.end(), [&](const Product &p)
                            { return p.name == name; });
        if (it != products.end())
        {
            products.erase(it, products.end());
            saveProducts();
            cout << "Product deleted.\n";
        }
        else
        {
            cout << "Product not found.\n";
        }
    }
    else
    {
        cout << "Invalid choice.\n";
    }
}

int main()
{
    cout << "Welcome to Business Management System\nEnter Password: ";
    string input_password;
    cin >> input_password;
    cin.ignore();

    if (input_password != "123")
    {
        cout << "Incorrect password. Exiting...\n";
        return 0;
    }

    BusinessManagement system;
    system.mainMenu();
    return 0;
}
