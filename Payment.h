#ifndef PAYMENT_H
#define PAYMENT_H

#include <iostream>
#include <string>
#include "Cart.h"
using namespace std;

//Superclass: Payment 
class Payment{
public: 
	double sum_price; //stores the total price that customer needs to pay
	string user_name; 
	string method_name;

	Payment();
	void setPrice(Cart *order_cart); //gets the sum price from the card array
	string getPaymentMethod();
	virtual void setPaymentInfo(); //gets the customer's name 
	virtual void getPaymentInfo(); //allows the sub classes to define this fucntion
    ~Payment();
};


//Subclass of Payment: Card
class Card: public Payment{
//private:
	
public:
	string card_num;  //card number is 16 digit long
	string exp_date;   //card expiration date
	string cvv;
	string card_name;  //card holder's name
					   //the name as displayed on the card

	Card();
	char card_end_num[4];  //the last 4 digits of the card number 
	virtual void getPaymentInfo();
	virtual void setPaymentInfo();
	~Card();
};


//Subclass of Payment: Cash
class Cash: public Payment{
//private:
	

public:
	double change;
	double amount_paid;
	Cash();
	void setAmountPaid();
	double getAmountPaid();
	double getChange();
	virtual void setPaymentInfo();
	virtual void getPaymentInfo();
	~Cash();
};


//Subclass of Payment: LaterPay
class LaterPay: public Payment{
//private:
	
public:
	string card_num;  //card number is 16 digits long
	int installments_num;
	string installments_num_str;
	double price_per_installment;
	string exp_date;   // card expiration date
	string cvv;
	string card_name;  //card holder's name
					   //the name as displayed on the card
	
	char card_end_num[4];  //last 4 digits of card for customer's 
						  //reference printed in receipt
	LaterPay();
	virtual void setPaymentInfo();
	virtual void getPaymentInfo();
	int getInstallmentsNum();
	double getPricePerInstallment();
	~LaterPay();
};
#endif







