#ifndef PAYMENT_H
#define PAYMENT_H
#ifndef CARD_H
#define CARD_H
#ifndef LATERPAY_H
#define LATERPAY_H
#ifndef CASH_H
#define CASH_H
#include <iostream>
#include <string>
#include "Cart.h"
using namespace std;

//Superclass: Payment 
class Payment{
public: 
	double sum_price; //stores the total price that customer needs to pay
	string user_name; 

	Payment();
	double getTotalPrice(Cart *order_cart); //gets the sum price from the card array
	virtual void setPaymentInfo(); //gets the customer's name 
	virtual void getPaymentInfo(); //allows the sub classes to define this fucntion
	~Payment();
};
#endif

//Subclass of Payment: Card
class Card: public Payment{
private:
	int card_num[16];  //card number is 16 digit long
	string exp_date;   //card expiration date
	int cvv;
	string card_name;  //card holder's name
					   //the name as displayed on the card
	
	virtual void setPaymentInfo();

public:
	Card();
	int card_end_num[4];  //the last 4 digits of the card number 
	virtual void getPaymentInfo();
	~Card();
};
#endif

//Subclass of Payment: Cash
class Cash: public Payment{
private:
	double change;
	double amount_paid;
	virtual void setPaymentInfo();

public:
	Cash();
	void setAmountPaid();
	double getAmountPaid();
	double getChange();
	virtual void getPaymentInfo();
	~Cash();
};
#endif

//Subclass of Payment: LaterPay
class LaterPay: public Payment{
private:
	int card_num[16];  //card number is 16 digits long
	int installments_num;
	double price_per_installment;
	string exp_date;   // card expiration date
	int cvv;
	string card_name;  //card holder's name
					   //the name as displayed on the card
	virtual void setPaymentInfo();

public:
	int card_end_num[4];  //last 4 digits of card for customer's 
						  //reference printed in receipt
	LaterPay();
	virtual void getPaymentInfo();
	int getInstallmentsNum();
	double getPricePerInstallment();
	~LaterPay();
};
#endif




