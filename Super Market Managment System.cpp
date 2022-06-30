#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

// method declaration
void main_menu();
void customer_menu();
void admin_auth();
void admin_menu();
void add_product();
void view_all_product();
void view_all_products_for_customer();
void purchase();
bool check_product_id_is_found(int product_id);

// structue declaration and defination
struct super{
    int product_id[20];
    string name[20];
    float price[20];
    string measurement[20];
    int quantity[20];
};
// global array of pointer declaration
int *ptr_product_id[20];
string *ptr_name[20];
float *ptr_price[20];
string *ptr_measurement[20];
int *ptr_quantity[20];

// shows total number product found in the list
int counter = 0;

int main()
{
    main_menu();
    return 0;
}

void main_menu(){
    system("CLS");
    int main_menu_choice;

    cout<<"WELCOME TO ALL IN ONE SUPERMARKET\n";
    cout<<"1 for Customer\n2 for Admin\n3 for Exit\n>";
    cin>>main_menu_choice;

    if(main_menu_choice == 1)
        customer_menu();
    else if(main_menu_choice == 2)
        admin_auth();
    else if(main_menu_choice == 3)
        system("EXIT");
    else
        cout<<"Wrong choice!";
}

void customer_menu()
{
    system("CLS"); //clear screen

    int customer_menu_choice;
    cout<<"CUSTOMER MENU\n";
    cout<<"1 for View all products\n2 for Purchase\n3 for Back\n>";
    cin>>customer_menu_choice;

    switch(customer_menu_choice){
        case 1:
            view_all_products_for_customer();
            break;
        case 2:
            purchase();
            break;
        case 3:
            main_menu();
            break;
        default:
            cout<<"Wrong choice. Try later.";
    }
}

void admin_auth(){
    system("CLS"); //clear screen

    int pin_code;
    cout<<"Enter a four digit admin pin code\n>";
    cin>>pin_code;
    if(pin_code != 1234){
        while(pin_code != 1234){
            cout<<"Wrong pin code enter again\n>";
            cin>>pin_code;
        }
        admin_menu();
    }
    else{
        admin_menu();
    }
}

void admin_menu(){
    system("CLS"); //clear screen

    int admin_menu_choice;
    cout<<"ADMIN MENU\n";
    cout<<"1 for Add product\n2 for View all products\n3 for Back\n>";
    cin>>admin_menu_choice;

    switch(admin_menu_choice){
        case 1:
            add_product();
            break;
        case 2:
            view_all_product();
            break;
        case 3:
            main_menu();
            break;
        default:
            cout<<"Wrong choice. Try later.";
    }
}

void add_product(){
    system("CLS"); //clear screen

    int add_count;
    cout<<"How many product do you want to add\n>";
    cin>>add_count;
    super s;

    for(int i=counter; i<(add_count+counter); i++){
        system("CLS"); //clear screen
        cout<<"Enter Product Info for Product "<<(i+1)<<endl;
		int check_id,count;
        do{
            cout<<"Enter unique product id\n>";
            cin>>s.product_id[i];
            check_id = s.product_id[i];
            for(int i=0; i<add_count; i++){
            	if(check_id == s.product_id[i]){
            		count++;
            		while(count > 1){
            			system("cls");
            			cout<<"duplicate product id.Enter again!!!\n";
            			cout<<"Enter unique product id\n>";
            			cin>>s.product_id[i];
            			if (check_id != s.product_id[i]){
							count = 0;
						}	
					}
				}
			}
        } while(check_product_id_is_found(s.product_id[i]));
        ptr_product_id[i] = &s.product_id[i];

        cout<<"Enter product name\n>";
        cin.ignore();
        getline(cin, s.name[i]);
        ptr_name[i] = &s.name[i];

        cout<<"Enter product price\n>";
        cin>>s.price[i];
        ptr_price[i] = &s.price[i];

        cout<<"Enter product measurement\n>";
        cin>>s.measurement[i];
        ptr_measurement[i] = &s.measurement[i];

        cout<<"Enter product quantity\n>";
        cin>>s.quantity[i];
        ptr_quantity[i] = &s.quantity[i];
    }
    counter=counter+add_count;

    admin_menu();
}

void view_all_product(){
    system("CLS"); //clear screen
    cout<<"All products\n";
    cout<<"Product ID\t\tProduct Name\t\tPrice\t\tMeasurement\t\tQuantity\n";
    for(int i=0; i<counter; i++){
        cout<<*ptr_product_id[i]<<"\t\t\t";
        cout<<*ptr_name[i]<<"\t\t\t";
        cout<<*ptr_price[i]<<"\t\t";
        cout<<*ptr_measurement[i]<<"\t\t\t";
        cout<<*ptr_quantity[i]<<"\n";
    }

    system("PAUSE"); //system pauses for accepting any key value from user
    admin_menu();
}

void view_all_products_for_customer(){
    system("CLS"); //clear screen
    cout<<"All products\n";
    cout<<"Product ID\t\tProduct Name\t\tPrice\t\tMeasurement\t\tQuantity\n";
    for(int i=0; i<counter; i++){
        cout<<*ptr_product_id[i]<<"\t\t\t";
        cout<<*ptr_name[i]<<"\t\t\t";
        cout<<*ptr_price[i]<<"\t\t";
        cout<<*ptr_measurement[i]<<"\t\t\t";
        cout<<*ptr_quantity[i]<<"\n";
    }

    system("PAUSE"); //system pauses for accepting any key value from user
    customer_menu();
}

bool check_product_id_is_found(int product_id){
    for(int i=0; i<counter; i++){
        if(*ptr_product_id[i] == product_id){
            return true;
        }
    }
    return false;
}

void purchase(){
    system("CLS"); //clear screen

    int purchase_product_id;
    cout<<"Enter product id\n";
    cin>>purchase_product_id;

    int found_index = -1;
    for(int i=0; i<counter; i++){
        if(*ptr_product_id[i] == purchase_product_id){
            found_index = i;
        }
    }

    if(found_index == -1){
        cout<<"The entered product id not found. Please check our product list\n";
        system("PAUSE");
        view_all_products_for_customer();
    }
    else {
        int purchase_quantity;

        do{
            cout<<"\nTotal quantity found in our store is "<<*ptr_quantity[found_index]<<"\n";
            cout<<"Enter quantity\n>";
            cin>>purchase_quantity;
        }while(purchase_quantity > *ptr_quantity[found_index]);


        float total_price = purchase_quantity * (*ptr_price[found_index]);
        cout<<"Single price = "<<*ptr_price[found_index]<<endl;
        cout<<"Purchase Quantity = "<<purchase_quantity<<endl;
        cout<<"Total price = "<<total_price<<endl;

        int confirmation;
        cout<<"\nAre you sure do you want to continue\n1 for Yes\n2 for No\n>";
        cin>>confirmation;
        if(confirmation == 1){
            system("CLS");

            cout<<"\t\t\t\tALL IN ONE Super Market\t\t\t\tDATE: April 04,2022\n";
            cout<<"_______________________________________________________________________________________________\n";
            cout<<"Product ID\tProduct Name\tSingle Price\tMeasurement\tQuantity\tTotal Price\t\n";
            cout<<"_______________________________________________________________________________________________\n";
            cout<<*ptr_product_id[found_index]<<"\t\t";
            cout<<*ptr_name[found_index]<<"\t\t";
            cout<<*ptr_price[found_index]<<"\t\t";
            cout<<*ptr_measurement[found_index]<<"\t\t";
            cout<<purchase_quantity<<"\t\t";
            cout<<total_price<<"\n";
            cout<<"_______________________________________________________________________________________________\n\n\n";
            cout<<"\t\t\t\tThank you for choosing us\n\n";
            cout<<"\t\t\t\t  For more information\n";
            cout<<"\t\t\t\t  ____________________\n";
            cout<<"\t\t\t\tContact Natnael teshome \n";
            cout<<"\t\t\t\t  nteshome84@gmail.com  \n:";   
            //update product quantity
            *ptr_quantity[found_index] = *ptr_quantity[found_index] - purchase_quantity;
            system("PAUSE");
            customer_menu();
        }
        else {
            main_menu();
        }
    }
}

