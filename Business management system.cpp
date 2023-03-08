// Business Management system:
#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;

class joy
{
public:
    string name[20],buy_price[20],sell_price[20];
    int total=0;

    void main_manu();
    void add_product();
    void show_product();
    void search_product();
    void edit_product();
    void delete_product();

};
    void main_manu();
    void add_product();
    void show_product();
    void search_product();
    void edit_product();
    void delete_product();

int main()
{
    cout<<"\t\t$ Welcome to Business Management System $.";
    cout<<"\n\n\t\tEnter your password : ";

    int pass;
    cin>>pass;

    if(pass==123)
    {
        cout<<"\n\n\t\t **Business Management System features**\n";
    }
    else
    {
        cout<<"Your password is wrong";
        return 0;
    }
    joy ob;
    ob.main_manu();
    return 0;
}

void joy::main_manu()
{

    while(1)
    {
        cout<<endl<<"\t\t 1. Add product"
        <<endl<<"\t\t 2. Show all product"
        <<endl<<"\t\t 3. Search product"
        <<endl<<"\t\t 4. Edit / Remove"
        <<endl<<"\t\t 5. Delete product"
        <<endl<<"\t\t 6. Log out\n\n\t\t:";
    int a;
    cin>>a;
    if(a==6)
    {
        cout<<"\n\t ** Log out **\n";break;
    }
        switch(a)
        {
    case 1:
        add_product();       break;
    case 2:
        show_product();      break;
    case 3:
        search_product();    break;
    case 4:
        edit_product();      break;
    case 5:
        delete_product();    break;
        }
    }

}

void joy::add_product()
{
    fstream file;
        file.open("data.txt");

    int choice;
    cout<<"\n\n\t\t How many products details want to add: ";
    cin>>choice;

    if(total==0)
    {
        for(int i=0; i<choice;i++)
        {
            cout<<"\n\n\tEnter data of product    :"<<i+1;
            cout<<"\n\n\tEnter product name       :";
            cin>>name[i];
            cout<<"\tEnter product buy price  :";
            cin>>buy_price[i];
            cout<<"\tEnter product sell price :";
            cin>>sell_price[i];

         file<<name[i]
            <<endl<<buy_price[i]
            <<endl<<sell_price[i]<<endl;
        }

    }
    else
    {
        for(int i=total; i<total+choice;i++)
        {
            cout<<"\n\n\tEnter data of product    :"<<i+1;
            cout<<"\n\n\tEnter product name       :";
            cin>>name[i];
            cout<<"\tEnter product buy price  :";
            cin>>buy_price[i];
            cout<<"\tEnter product sell price :";
            cin>>sell_price[i];

             file<<name[i]
            <<endl<<buy_price[i]
            <<endl<<sell_price[i]<<endl;


            }
    }
    total=total+choice;
    file.close();

}


void joy::show_product()
{
     ifstream file;
        file.open("data.txt",std::ios::in);
          string line;
        while(getline(file,line))
        {
            cout<<"\n\t\t"<<line;
        }


    for(int i=0; i<total; i++)
    {
        cout<<"\n\n\t***\tData of  product :"<<i+1<<"\t***"<<endl<<endl;
        cout<<"\tProduct name       :"<<name[i]<<endl;
        cout<<"\tProduct buy price  :"<<buy_price[i]<<endl;
        cout<<"\tProduct sell price :"<<sell_price[i]<<endl<<endl;

    }
    file.close();

}

void joy::search_product()
{
    cout<<"Enter product name which you want to see : ";

    string product_name;
    cin>>product_name;

   for(int i=0; i<total; i++)
   {
       if(product_name==name[i])
       {
        cout<<"\n\n\t***\tData of  product :"<<i+1<<"\t***"<<endl<<endl;
        cout<<"\tProduct name       :"<<name[i]<<endl;
        cout<<"\tProduct buy price  :"<<buy_price[i]<<endl;
        cout<<"\tProduct sell price :"<<sell_price[i]<<endl<<endl;
       }

   }

}

void joy::edit_product()
{

    cout<<"Enter product name which you want to see : ";

    string product_name;
    cin>>product_name;

   for(int i=0; i<total; i++)
   {
       if(product_name==name[i])
       {
        cout<<"Previous data : ";
        cout<<"\n\n\t***\tData of  product :"<<i+1<<"\t***"<<endl<<endl;
        cout<<"\tProduct name       :"<<name[i]<<endl;
        cout<<"\tProduct buy price  :"<<buy_price[i]<<endl;
        cout<<"\tProduct sell price :"<<sell_price[i]<<endl<<endl;

        cout<<"\n\n\tEdit your information :";
        cout<<"\n\n\tEnter product name       :";
        cin>>name[i];
        cout<<"\tEnter product buy price  :";
        cin>>buy_price[i];
        cout<<"\tEnter product sell price :";
        cin>>sell_price[i];
        }
    }

}

void joy::delete_product()
{

    int x;

    cout<<"Press 1 to delete all data"<<endl;
    cout<<"Press 2 to delete specific data"<<endl;

    cin>>x;

    if(x==1)
    {
        total=0;
        cout<<"Deleted all data"<<endl;

    }
    else
    {
        string id_no;
        cout<<"Press id no which you want to delete"<<endl;
        cin>>id_no;
        for(int i=0; i<total; i++)
        {
            if(id_no==name[i])
            {
                for(int j=i; j<total; j++)
                {
                    name[j]=name[j+1];
                }
                total--;
                cout<<"Your record is delete"<<endl;
            }
        }
    }
}




