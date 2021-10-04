
#include "Receipt.h"

//basic class Receipt
//implementation of the default Receipt constructor
Receipt::Receipt(){
    Product* cart_list = nullptr;
    double total_price = 0;
    Payment method = " ";
    char* date_time = nullptr;
}
//Receipt with the list of product, total price and payment method
Receipt::Receipt(Product* plist, double ptotal_price, Payment pmethod){
    Product* cart_list = plist;
    double total_price = ptotal_price;
    Payment method = pmethod;
    char* date_time = nullptr;
}

//get the list of product
Product* Receipt::getCart(){
    return cart_list;
}

//get the total price
double Receipt::getTotalPrice(){
    return total_price;
}

//get Payment Method
Payment Receipt::getPaymentMethod(){
    return method;
}

//get current time
char* Receipt::getDateTime(){
    //current date and time on the current system
    time_t now = time(0);

    //convert now to string form
    char* date_time = ctime(&now);

    return date_time;
}

//destructor to free heap memory
Receipt::~Receipt(){
    delete[] cart_list;
    delete date_time;
}

//subclass ReceiptByEmail
//default constructor
ReceiptByEmail::ReceiptByEmail(){
    string email = " ";
}

//ReceiptByEmail with the list of product, total price and payment method
ReceiptByEmail::ReceiptByEmail(Product* plist, double ptotal_price, Payment pmethod){
    Product* cart_list = plist;
    double total_price = ptotal_price;
    Payment method = pmethod;
    char* date_time = nullptr;
}

//get email from the user
string ReceiptByEmail::getDetails(){
    cout << "Enter your email address below:" << endl;
    cin >> email;
    return email;
}

//notification for sent receipt
void ReceiptByEmail::notify(){
    cout << "The receipt has been successfully sent to " << email << endl;
}

ReceiptByEmail::~ReceiptByEmail(){

}

//subclass ReceiptByMessage
//default constructor
ReceiptByMessage::ReceiptByMessage(){
    string phone_number = " ";
}

//ReceiptByMessage with the list of product, total price and payment method
ReceiptByMessage::ReceiptByMessage(Product* plist, double ptotal_price, Payment pmethod){
    Product* cart_list = plist;
    double total_price = ptotal_price;
    Payment method = pmethod;
    char* date_time = nullptr;
}

//get phone number from the user
string ReceiptByMessage::getDetails(){
    cout << "Enter your phone number below:" << endl;
    cin >> phone_number;
    return phone_number;
}

//notification for sent receipt
void ReceiptByMessage::notify(){
    cout << "The receipt has been successfully sent to " << phone_number << endl;
}

ReceiptByMessage::~ReceiptByMessage(){

}


