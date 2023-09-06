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
    void rem();
    void shoppingList();
    void shoppingReceipt();
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
    cout << "\n\t\t\t   Please Select : ";
    cin >> choice;

    switch (choice)
    {

    case 1:
        cout << "\t\t\t Please Login \n\n";
        cout << "\t\t\t Enter Email : ";
        // cin.get();
        // getline(cin,email);
        cin>>email;
        cout << "\t\t\t Enter Password : ";
        // cin.get();
        // getline(cin,password);
        cin>>password;
        
        if(email == "nainagupta@gmail.com" && password == "naina"){
            administrator();
        }
        else{
            cout << "\n\t\t\tInvalid Email/Password\n\n";
        }
        break;

   case 2:
   {
    buyer();
    break;
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
        rem();
        break;

        case 4:
        menu();
        break;

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
        shoppingReceipt();
        break;

        case 2:
        menu();

        default:
        cout << "Invalid choice!";
    }
    goto m;
}

void Shopping :: add()
{
    m:
    fstream data,fout;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout << "\n\n\t\t\t Add new product";
    cout << "\n\n\t Product code of the product ";
    cin >> productCode;
    cout << "\n\n\t Name of the Product ";
    // cin.get();
    // getline(cin,productName);
    cin>>productName;
    cout << "\n\n\t Price of the product ";
    cin >> price;
    cout << "\n\n\t Discount on the Product ";
    cin >> discount;

    data.open("C:/Users/Babloo/Desktop/SuperMarketBilingSystem/database.txt", ios::in);
    if(!data)
    {
        fout.open("C:/Users/Babloo/Desktop/SuperMarketBilingSystem/database.txt", ios::app | ios::out);
        fout << " " << productCode << " " << productName << " " << price << " " << discount << "\n";
        fout.close();
    }
    else
    {
        data>>c>>n>>p>>d;
        while(!data.eof())
        {
            if(c == productCode)
            {
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();
    if(token == 1)
    goto m;
    else{
        fout.open("C:/Users/Babloo/Desktop/SuperMarketBilingSystem/database.txt", ios::app | ios::out);
        fout << " " << productCode << " " << productName << " " << price << " " << discount << "\n";
        fout.close();
    }
}
    cout << "\n\n\t\t\t Record Inserted!";
}

void Shopping :: edit()
{
    fstream data, data1;
    int pkey;
    int token = 0;
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
                // cin.get();
                // getline(cin, n);
                cin>>n;
                cout << "\n\t\t Price of the product";
                cin>>p;
                cout << "\n\t\t Discount on the product";
                cin>>d;

                data1<<"\n" << c << " " << n << " " << p << " " << d << "\n";
                cout << "\n\n\t\t Record edited";
                token++;
            }else{
                data1<<" " << productCode << " " << productName << " " << price << " " << discount << "\n";
            }
            data>>productCode>>productName>>price>>discount;
        }
        data.close();
        data1.close();
        remove("C:/Users/Babloo/Desktop/SuperMarketBilingSystem/database.txt");
        rename("C:/Users/Babloo/Desktop/SuperMarketBilingSystem/database1.txt","C:/Users/Babloo/Desktop/SuperMarketBilingSystem/database.txt");
        if(token == 0){
            cout << "\n\n Record not found Sorry!";
        }
    }
}

void Shopping :: rem()
{
    fstream data, data1;
    int pkey;
    int token= 0;
    cout << "\n\n\t Delete product";
    cout << "\n\n\t Enter product code: ";
    cin >> pkey;
    data.open("C:/Users/Babloo/Desktop/SuperMarketBilingSystem/database.txt", ios::in);
    if(!data){
        cout << "\nFile doesn't exist";
    }else{
        data1.open("C:/Users/Babloo/Desktop/SuperMarketBilingSystem/database1.txt",ios::app | ios::out);
        data>>productCode>>productName>>price>>discount;
        while(!data.eof()){
            if(productCode == pkey){
                cout << "\n\n\t Product deleted successfully";
                token++;
            }
            else
            {
                data1 << " " << productCode << " " << productName << " " << price << " " << discount << "\n";
            }
            data>>productCode>>productName>>price>>discount;
        }
        data.close();
        data1.close();

        remove("C:/Users/Babloo/Desktop/SuperMarketBilingSystem/database.txt");
        rename("C:/Users/Babloo/Desktop/SuperMarketBilingSystem/database1.txt", "C:/Users/Babloo/Desktop/SuperMarketBilingSystem/database.txt");

        if(token == 0){
            cout << "\n\n Record not be found";
        }
    }
}

void Shopping :: shoppingList()
{
    ifstream data;
    data.open("C:/Users/Babloo/Desktop/SuperMarketBilingSystem/database.txt", ios::in);
    cout << "\n\n_____________________________________________________________________\n";
    cout << "P.No\t\tP-Name\t\tP-Price\n";
    cout << "\n\n_____________________________________________________________________\n";
    data >> productCode >> productName >> price >> discount;
    while(!data.eof()){
        cout << productCode << "\t\t" << productName << "\t\t" << price << "\n";
        data >> productCode >> productName >> price >> discount;
    }
    data.close();
}

void Shopping :: shoppingReceipt()
{
    m:
    fstream data;
    int arrCode[100];
    int arrQuantity[100];
    char choice;
    int counter = 0;
    float amount = 0;
    float discount = 0;
    float totalVariable = 0;
    cout << "\n\n\t\t\t\t RECEIPT";
    data.open("C:/Users/Babloo/Desktop/SuperMarketBilingSystem/database.txt",ios::in);
    if(!data){
        cout << "\n\n Empty Database";
    }else{
        data.close();
        shoppingList();
        cout << "\n______________________________________________________\n";
        cout << "\n|                                                    |\n";
        cout << "\n               Please place the order                 \n";
        cout << "\n|                                                    |\n";
        cout << "\n______________________________________________________\n";

        do
        {
            cout << "\n\n Enter product code : ";
            cin >> arrCode[counter];
            cout << "\n\n Enter product quantity : ";
            cin >> arrQuantity[counter];
            for(int i = 0; i < counter; i++){
                if(arrCode[counter] == arrCode[i]){
                    cout << "\n\n Duplicate product code : Please try again!";
                    goto m;
                }
            }
            counter++;
            cout << "\n\n Do you want to buy another product? if yes then press y else n : ";
            cin >> choice;
        }
        while(choice =='y');
        
        cout << "\n\n\t\t\t____________________RECEIPT______________________\n";
        cout << "\nProduct No\t Product Name\t Product Quantity\t Price\t\t Amount\t\tAmount with discount\n";

        for(int i = 0; i < counter; i++){
            data.open("C:/Users/Babloo/Desktop/SuperMarketBilingSystem/database.txt",ios::in);
            data>>productCode>>productName>>price>>discount;
            while(!data.eof()){
                if(productCode == arrCode[i]){
                    amount = price*arrQuantity[i];
                    discount = amount - (amount*discount/100);
                    totalVariable = totalVariable+discount;
                    cout << "\n"<<productCode<<"\t\t "<<productName<<"\t\t\t"<<arrQuantity[i]<<"\t\t  "<<price<<"\t\t  "<<amount<<"\t\t   "<<discount<<"\n";
                }
                data>>productCode>>productName>>price>>discount;
            }
        }
        data.close();
    }
    cout << "\n\n____________________________________________________________";
    cout << "\n\n\t\t\t Total Amount: " << totalVariable <<"\t\t\n";
}

int main()
{
    Shopping s;
    s.menu();
    return 0;
}