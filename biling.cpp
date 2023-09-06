#include<iostream>
#include<fstream>
using namespace std;
class Shopping
{
    private:
    int productCode;
    float price;
    float discount;
    string productName;

    public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void remove();
    void list();
    void receipt();
};

void Shopping :: menu()
{
    m:
    int choice;
    string email;
    string password;

    cout << "\t\t\t\t_________________________________________\n";
    cout << "\t\t\t\t                                         \n";
    cout << "\t\t\t\t           SuperMarket Main Menu         \n";
    cout << "\t\t\t\t                                         \n";
    cout << "\t\t\t\t_________________________________________\n";
    cout << "\t\t\t\t                                         \n";
    cout << "\t\t\t\t|  1) Administrator    |\n";
    cout << "\t\t\t\t                        \n";
    cout << "\t\t\t\t|  2) Buyer            |\n";
    cout << "\t\t\t\t                        \n";
    cout << "\t\t\t\t|  3) Exit             |\n";
    cout << "\n\t\t\t   Please Select";
    cin >> choice;

    switch (choice)
    {

    case 1:
        cout << "\t\t\t Please Login \n";
        cout << "\t\t\t Enter Email \n";
        cin >> email;
        cout << "\t\t\t Enter Password \n";
        cin >> password;
        
        if(email == "robby@gmail.com" && password == "robby@123"){
            administrator();
        }else{
            cout << "Invalid Email/Password";
        }
        break;

   case 2:
   {
    buyer();
   }

   case 3:
   {
    exit(0);
   }

    default:
    {
        cout << "Please Select the given option like(1,2,3)";
    }
    }

    goto m;     // goto is jump statement
}

void Shopping :: administrator()
{
    m:
    int choice;
    cout << "\n\n\n\t\t\t Administrator menu \n";
    cout << "\t\t\t|_____1) Add the product____|\n";
    cout << "\t\t\t|                           |\n";
    cout << "\t\t\t|_____2) Modify the product_|\n";
    cout << "\t\t\t|                           |\n";
    cout << "\t\t\t|_____3) Delete the product_|\n";
    cout << "\t\t\t|                           |\n";
    cout << "\t\t\t|_____4) Back to main menu__|\n";
    cout << "\t\t\t|                           |\n";

    cout << "\n\n\t Please Enter Your Choice";
    cin >> choice;

    switch (choice)
    {
        case 1:
        add();
        break;

        case 2:
        edit();
        break;

        case 3:
        remove();
        break;

        case 4:
        menu();

        default :
        cout << "Invalid choice!";
    }
    goto m;
}

void Shopping :: buyer()
{
    m:
    int choice;
    cout << "\t\t\t Buyer \n";
    cout << "_____________________\n";
    cout << "                     \n";
    cout << "\t\t\t1) Buy product \n";
    cout << "                     \n";
    cout << "\t\t\t2) Go back     \n";
    cout << "                     \n";
    cout << "\t\t\t Enter your choice : ";

    cin >> choice;
    switch (choice)
    {
        case 1:
        receipt();
        break;

        case 2:
        menu();
        break;

        default:
        cout << "Invalid choice";
    }
    goto m;
}

void Shopping :: add()
{
    m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout << "\n\n\t\t\t Add new product";
    cout << "\n\n\t Product code of the product ";
    cin >> productCode;
    cout << "\n\n\t Price of the product ";
    cin >> price;
    cout << "\n\n\t Name of the Product ";
    cin.get();
    getline(cin, productName);
    cout << "\n\n\t Discount on the Product ";
    cin >> discount;

    data.open("C:/Users/Babloo/Desktop/SuperMarketBilingSystem/database.txt", ios::in);
    if(!data){
        data.open("C:/Users/Babloo/Desktop/SuperMarketBilingSystem/database.txt", ios::app | ios:: out);
        data << " " << productCode << " " << productName << " " << price << " " << discount << endl;
        data.close();
    }
    else{
        data>>c>>n>>p>>d;
        while(!data.eof()){
            if(c == productCode){
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();

    if(token == 1)
    goto m;
    else{
        data.open("C:/Users/Babloo/Desktop/SuperMarketBilingSystem/database.txt", ios::app | ios:: out);
        data << " " << productCode << " " << productName << " " << price << " " << discount << endl;
        data.close();
    }
    }
    cout << "\n\n\t\t\t Record Inserted";
}

void Shopping :: edit()
{
    fstream data, data1;
    int pkey;
    int token;
    int c;
    float p;
    float d;
    string n;
    cout << "\n\t\t\t Modify the product";
    cout << "\n\t\t\t Product code";
    cin>>pkey;
    data.open("C:/Users/Babloo/Desktop/SuperMarketBilingSystem/database.txt", ios::in);
    if(!data)
    {
        cout << "\n\n File doesn't exist!";
    }
    else{
        data1.open("C:/Users/Babloo/Desktop/SuperMarketBilingSystem/database1.txt", ios::app | ios::out);
        data>>productCode>>productName>>price>>discount;
        while(!data.eof()){
            if(pkey == productCode){
                cout << "\n\t\t Product new code";
                cin>>c;
                cout << "\n\t\t Name of the product";
                cin.get();
                getline(cin, n);
                cout << "\n\t\t Price of the product";
                cin>>p;
                cout << "\n\t\t Discount on the product";
                cin>>d;
            }
        }
    }
}