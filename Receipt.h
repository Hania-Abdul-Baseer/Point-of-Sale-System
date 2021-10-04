#include <iostream>
#include <ctime>
#include <string>
#include "Cart.h"
#include "Product.h"
#include "Payment.h"
using namespace std;

#ifndef RECEIPT_H
#define RECEIPT_H

//abstract class Receipt
class Receipt{
public:
    //constructor
    Receipt();
    Receipt(Product* plist, double ptotal_price, Payment pmethod);

    //member functions
    Product* getCart();
    double getTotalPrice();
    Payment getPaymentMethod();
    char* getDateTime();
    virtual string getDetails()=0;
    virtual void notify()=0;

    //destructor
    ~Receipt();

private:
    //member variables
    Product* cart_list;
    double total_price;
    Payment method;
    string date_time;
};

//subclass ReceiptByEmail
class ReceiptByEmail: public Receipt{
public:
    //constructor
    ReceiptByEmail();
    ReceiptByEmail(Product* plist, double ptotal_price, Payment pmethod);

    //member functions
    string getDetails();
    void notify();

    //destructor
    ~ReceiptByEmail();

private:
    //member variables
    string email;

};

//subclass ReceiptByMessage
class ReceiptByMessage: public Receipt{
public:
    //constructor
    ReceiptByMessage();
    ReceiptByMessage(Product* plist, double ptotal_price, Payment pmethod);

    //member functions
    string getDetails();
    void notify();

    //destructor
    ~ReceiptByMessage();

private:
    //member variables
    string phone_number;

};

#endif
