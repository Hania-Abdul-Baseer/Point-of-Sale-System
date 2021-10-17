//a test file for the class Receipt
#include "Receipt.h"


int main(){

    //initial values
    Product* cart = new Product[5];
    int count = 5;
    double total_price = 10.05;
    Payment* method = new Card;

    //initialise two Receipt variables
    //Receipt R1;
    ReceiptByEmail R1;
    ReceiptByMessage R2;
    Receipt R3;

    //testing functions
    //print list of product
    R2.displayReceipt(cart, count, total_price, method);


    //get details and check valid input

    cout << R1.checkValidInput(R1.getDetails()) << endl;
    cout << R1.checkValidInput(R1.getDetails()) << endl;
    cout << R1.checkValidInput(R1.getDetails()) << endl;
    cout << R1.checkValidInput(R1.getDetails()) << endl;
    cout << R1.checkValidInput(R1.getDetails()) << endl;
    cout << R1.checkValidInput(R1.getDetails()) << endl;
    cout << R2.checkValidInput(R2.getDetails()) << endl;
    cout << R2.checkValidInput(R2.getDetails()) << endl;
    cout << R2.checkValidInput(R2.getDetails()) << endl;
    cout << R2.checkValidInput(R2.getDetails()) << endl;
    cout << R2.checkValidInput(R2.getDetails()) << endl;

    //notification
    R1.notify();
    R2.notify();


    //destructor
    //R1.~Receipt();
    R1.~Receipt();
    R2.~Receipt();


    return 0;
}
