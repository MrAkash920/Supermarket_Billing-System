#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class shopping {
private:
    int id;
    string name;
    int price;
    int quantity;
    int discount;
    int total;
public:
    void menu();
    void administrator();
    void customer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};

void shopping::menu() {
m:
    int choice;
    string email;
    string password;

    cout << "\t\t\t\t______________________________________________________\n";
    cout << "\t\t\t\t                                                      \n";
    cout << "\t\t\t\t|                   Supermarket Menu                  |\n";
    cout << "\t\t\t\t                                                      \n";
    cout << "\t\t\t\t______________________________________________________\n";
    cout << "\t\t\t\t| 1}Administrator |\n";
    cout << "\t\t\t\t|                 |\n";
    cout << "\t\t\t\t| 2}Customer      |\n";
    cout << "\t\t\t\t|                 |\n";
    cout << "\t\t\t\t| 3}Exit          |\n";
    cout << "\t\t\t\t|_________________|\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "Enter your email: ";
        cin >> email;
        cout << "Enter password: ";
        cin >> password;

        if (email == "admin@cumail.in" && password == "admin") {
            administrator();
        }
        else {
            cout << "Invalid email or password";
        }
        break;

    case 2:
        customer();
        break;
    case 3:
        exit(0);
        break;
    default:
        cout << "Invalid choice";
        goto m;
    }
}

void shopping::administrator()
{
m:
    int choice;
    cout << "\n\n\t\t\t\t Administrator Menu ";
    cout << " \n\n\t\t\t|_____1.Add item_____|\n";
    cout << "\t\t\t|_____2.Edit item____|\n";
    cout << "\t\t\t|_____3.Remove item__|\n";
    cout << "\t\t\t|_____4.Exit_________|\n";

    cout << "Enter your choice: ";
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
        exit(0);
        break;
    default:
        cout << "Invalid choice";
        goto m;
    }
}

void shopping::customer() {
m:
    int choice;
    cout << " \t\t\t|     Customer        |\n";
    cout << "\t\t\t_______________________________\n";
    cout << " \t\t\t|_____1.Buy Product________|\n";
    cout << "                                       \n";
    cout << " \t\t\t|_____2.List of Products____|\n";
    cout << "                                       \n";
    cout << "\t\t\t Enter your Choice: \n";
    cin >> choice;

    switch (choice) {
    case 1:
        receipt();
        break;
    case 2:
        list();
        break;
    default:
        cout << "Invalid choice";
        goto m;
    }
}

void shopping::add() {
m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout << "Add new Product\n";
    cout << "Enter the product id: ";
    cin >> id;
    cout << "Name of the Product: ";
    cin >> name;
    cout << "Price of the Product: ";
    cin >> price;
    cout << "Discount of the Product:";
    cin >> discount;

    data.open("database.txt", ios::in);

    if (!data) {
        data.open("database.txt", ios::out);
        data << " " << id << " " << name << " " << price << " " << discount << " " << "\n";
        data.close();
    }
    else {
        data >> c >> n >> p >> d;
        while (!data.eof()) {
            if (c == id) {
                token++;
                break;
            }
            data >> c >> n >> p >> d;
        }
        data.close();
    }
    if (token == 1) {
    
    }
    else {
        data.open("database.txt", ios::app);
        data << " " << id << " " << name << " " << price << " " << discount << " " << "\n";
        data.close();
    }
    cout << "\n\n\t\t\t\tItem added successfully";
    goto m;
}

void shopping::edit() {
m:
    fstream data, data1;
    int id;
    int token = 0;
    string name;
    float price;
    float discount;

    cout << "Edit Product\n";
    cout << "Enter the product id: ";
    cin >> id;

    data.open("database.txt", ios::in);

    if (!data) {
        cout << "File not found";
    }
    else {
        data1.open("database1.txt", ios::app);
        while (data >> id >> name >> price >> discount) {
            if (id == id) {
                cout << "\n\n\t\tProduct code: " << id;
                cout << "\n\n\t\tProduct name: " << name;
                cout << "\n\n\t\tProduct price: " << price;
                cout << "\n\n\t\tProduct discount: " << discount;

                cout << "\n\n\t\tEnter new product name: ";
                cin >> name;
                cout << "\n\n\t\tEnter new product price: ";
                cin >> price;
                cout << "\n\n\t\tEnter new product discount: ";
                cin >> discount;

                data1 << id << " " << name << " " << price << " " << discount << "\n";
                cout << "\n\n\t\tItem edited successfully";
                token++;
            }
            else {
                data1 << id << " " << name << " " << price << " " << discount << "\n";
            }
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");
        if (token == 0) {
            cout << "\n\n\t\tItem not found";
        }
    }
    goto m;
}

void shopping :: rem(){
m:
    fstream data, data1;
    int pkey;
    int token = 0;
    cout <<"\n\n\t\t Remove Product";
    cout <<"\n\n\t\t Enter the product id: ";
    cin >> pkey;
    data.open("database.txt",ios::in);
    if(!data){
        cout << "File not found";
    }
    else{
        data1.open("database1.txt",ios::app);
        data>>id>>name>>price>>discount;
        while(!data.eof()){
            if(pkey == id){
                cout <<"Item removed successfully";
                token++;
            }
            else{
                data1 << " "<<id <<" "<<name<<" "<<price<<" "<<discount<<" "<<"\n";
            }
            data >> id >> name >> price >> discount;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");
        if (token == 0){
            cout << "Item not found";
        }
    }
    goto m;
}

void shopping::list() {
    fstream data;
    int c;
    data.open("database.txt", ios::in);
    cout << "\n\n|__________List of Product___________|";
    if (!data) {
        cout << "File not found";
    }
    else {
        data >> id >> name >> price >> discount;
        while (!data.eof()) {
            cout << "\n\n\t\tProduct code: " << id;
            cout << "\n\n\t\tProduct name: " << name;
            cout << "\n\n\t\tProduct price: " << price;
            cout << "\n\n\t\tProduct discount: " << discount;
            data >> id >> name >> price >> discount;
        }
        data.close();
    }
    
}

void shopping::receipt() {
m:
    fstream data;
    int arrc[100]; //array for code
    int arrq[100]; //array for quantity
    char choice;
    int c = 0;
    float amount = 0;
    float disc = 0;
    float total = 0;

    cout << "\n\n\t RECEIPT";
    data.open("database.txt", ios::in);
    if (!data) {
        cout << "Empty Database";
    }
    else {
        data.close();

        list();
        cout << "\n______________________________________________________\n";
        cout << "\n|                                                     |\n";
        cout << "n           Please Place the Order                        \n";
        cout << "\n|                                                     |\n";
        cout << "\n______________________________________________________\n";
        do {
            cout << "Enter the product code: ";
            cin >> arrc[c];
            cout << "Enter the quantity: ";
            cin >> arrq[c];
            for (int i = 0; i < c; i++) {
                if (arrc[c] == arrc[i]) {
                    cout << "Product already added. Please try again";
                    arrq[i] = arrq[i] + arrq[c];
                    goto m;
                }
            }
            c++;
            cout << "Do you want to add more items? (y/n)";
            cin >> choice;
        } while (choice == 'y' || choice == 'Y');
        cout << "\n\n\t\t\t\t_______________RECEIPT_______________";
        cout << "\n\n\t\t\t\tProduct Name\tProduct code\tQuantity\tPrice\tAmount";

        for (int i = 0; i < c; i++) {
            data.open("database.txt", ios::in);
            data >> id >> name >> price >> discount;
                        while (!data.eof()) {
                if (arrc[i] == id) {
                    cout << "\n\n\t\t\t\t" << name << "\t\t" << id << "\t\t" << arrq[i] << "\t\t" << price << "\t" << price * arrq[i];
                    amount = amount + (price * arrq[i]);
                    disc = disc + (price * arrq[i] * discount / 100);
                    total = amount - disc;
                    cout << "\n" << id << "\t" << name << "\t" << arrq[i] << "\t" << price << "\t" << amount << "\t" << disc;
                }
                data >> id >> name >> price >> discount;
            }
        }
        data.close();
    }
    cout << "\n\n\t\t\t\t____________________________________";
    cout << "\n\n\t\t\t\tTotal amount: " << amount;
}

int main() {
    shopping s;
    s.menu();
    return 0;
}