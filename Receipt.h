#ifndef RECEIPT_H
#define RECEIPT_H

//abstract class Receipt
class Receipt{
public:
    //constructor
    Receipt();

    //member functions
    void displayReceipt(Product* plist, int pitem_count, double ptotal_price, Payment* pmethod);
    virtual string getDetails();
    virtual bool checkValidInput(string input);
    virtual void notify();

    //destructor
    ~Receipt();


};

//subclass ReceiptByEmail
class ReceiptByEmail: public Receipt{
public:
    //constructor
    ReceiptByEmail();

    //member functions
    string getDetails();
    bool checkValidInput(string email);
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

    //member functions
    string getDetails();
    bool checkValidInput(string phone_number);
    void notify();


    //destructor
    ~ReceiptByMessage();

private:
    //member variables
    string phone_number;

};

#endif
