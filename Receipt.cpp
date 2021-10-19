#include "Receipt.h"

//basic class Receipt
//implementation of the default Receipt constructor
Receipt::Receipt(){

}


//function to display receipt
void Receipt::displayReceipt(Product* plist, int pitem_count, double ptotal_price, Payment* pmethod){
    //display Receipt header
    cout << "\n\n\t\t\tBest Buy Grocery Store\n\t\t\t\t 73 Rundle Mall\n\t\t\t   Adelaide SA 5000\n\t\t\twww.bestbuygrocery.com\n\t\t\tTelephone: 08 8000 8000\n\t\t\t ABN: 12 345 678 900\n\t\t\t      TAX INVOICE\n" << endl;

    //get current date time
    //current date and time on the current system
    time_t now = time(0);
    //convert now to string form
    char* date_time = ctime(&now);
    //print date time
    cout << "Date/Time -- " << date_time << endl;

    //product info
    int i = 0;
    while (i != pitem_count){
        if (plist[i].getQuantityRequired() != 0){
            cout << i+1 << ". " << plist[i].getProductName() << "\t\t\t\t\t" << plist[i].getProductPrice() << endl;
        }
        i++;
    }

    //total price
    cout << "TOTAL AUD" << "\t     " << ptotal_price << "\n" << endl;

    //payment info
    pmethod->getPaymentInfo();

    //extra info
    cout << "\nExchange and refund will not be available.\nThank you for shopping at Best Buy Grocery Store." << endl;

}

string Receipt::getDetails(){
    return " ";
}

bool Receipt::checkValidInput(string input){
    return " ";
}

void Receipt::notify(){

}

//destructor to free heap memory
Receipt::~Receipt(){

}

//subclass ReceiptByEmail
//default constructor
ReceiptByEmail::ReceiptByEmail(){
    string email = " ";
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

bool ReceiptByEmail::checkValidInput(string email){

    int length = email.length();
    for(int j = 1; j < length; j++){
        if (!((email[j] >= 'a' && email[j] <= 'z') || (email[j] >= 'A' && email[j] <= 'Z') || (email[j] >= '0' && email[j] <= '9') || (email[j] == '@') || (email[j] == '.'))){
            return false;
        }
    }

    int at_position = -1;
    int at_count = 0;
    int dot_position = -1;

    for (int i = 0; i < length; i++){
        if (email[i] == '@'){
            at_position = i;
            at_count++;
        }
        else if (email[i] == '.'){
            dot_position = i;
            break;
        }
    }


    if ((at_count != 1) || (at_position == -1) || (dot_position == -1) || (at_position > dot_position) || (dot_position == (length-1))){
        return false;
    }

    return true;
}

ReceiptByEmail::~ReceiptByEmail(){

}

//subclass ReceiptByMessage
//default constructor
ReceiptByMessage::ReceiptByMessage(){
    string phone_number = " ";
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

bool ReceiptByMessage::checkValidInput(string phone_number){
    int length = phone_number.length();
    if (length != 10){
        return false;
    }
    else{
        for (int i = 0; i < 10; i++){
            if (isdigit(phone_number[i]) == false){
                return false;
            }
        }
    }
    return true;
}

ReceiptByMessage::~ReceiptByMessage(){

}
