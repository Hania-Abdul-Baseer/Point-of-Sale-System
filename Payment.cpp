#include <iostream>
#include <string>
#include <cmath>
#include "Payment.h"
#include "Cart.h"
#include "ctype.h"
using namespace std;

//deafult payment constructor 
Payment::Payment(){
	sum_price = 0;
	user_name = " ";
}

string Payment::getPaymentMethod(){
	return method_name;
}

//calculates and stores the total price that customer needs to pay from the cart array
void Payment::setPrice(Cart *order_cart){
    sum_price = order_cart->getTotalPrice();
}

//asks and stores the customer's name
void Payment::setPaymentInfo(){
	cout<<"Enter your name: "<<endl;
	cin>>user_name;
}

//only defined by the sub classes
void Payment::getPaymentInfo(){
	////
}

//default destructor 
Payment::~Payment(){
	cout<<"Destroyed a Payment object"<<endl;
}

//Subclass of Payment: Card
//default Card constructor 
Card::Card(){
	exp_date = " ";
	cvv = " ";
	card_name = " ";
	method_name = "Card";
	card_num = " ";
}

//asks and stores all the info related to card payment 
void Card::setPaymentInfo(){

	cout<<"You have chosen the card payment method."<<endl;
	cout<<"Please enter your card details to complete payment"<<endl;
	cout<<"Cardholder Name: ";
	cin.ignore();
    getline(cin, card_name); 
	cout<<"\n";
	
	cout<<"Card Number: ";
	cin.ignore();
    getline(cin, card_num);
    
    while(card_num.length()!=15){
    	cout<<"\n"<<"Invalid card number. Card number must contain 16 digits."<<endl;
    	cout<<"Please enter the Card Number again: ";
		cin.ignore();
	    getline(cin, card_num);
    }
	cout<<"\n";

	cout<<"Card Expiration Date: ";
	cin>>exp_date;
	cout<<"\n";

	cout<<"Three Digit CVV Code: ";
	cin.ignore();
    getline(cin, cvv);  
    if(cvv.length()!=3){
    	cout<<"\n"<<"Invalid cvv code. Cvv code must contain 3 digits."<<endl;
    	cout<<"Please enter your three digit cvv code again: ";
		cin.ignore();
	    getline(cin, cvv);
    	while(cvv.length()!=2){
    		cout<<"\n"<<"Invalid cvv code. Cvv code must contain 3 digits."<<endl;
	    	cout<<"Please enter your three digit cvv code again: ";
			cin.ignore();
		    getline(cin, cvv);
       }
    }
    
	cout<<"\n";

//storing the last four ending digits of the card number for displaying when 
//needed for customer's reference 
	
	card_end_num[0] = card_num[11]; 
	card_end_num[1] = card_num[12];
	card_end_num[2] = card_num[13];
	card_end_num[3] = card_num[14];
}

//only displaying the payment mmethod name and ending 4 digits of card 
//for customer's reference
void Card::getPaymentInfo(){
 	cout<<"Paid with: Card ending in ";
 	cout<<card_end_num[0]<<card_end_num[1]<<card_end_num[2]<<card_end_num[3]<<endl;
 	cout<<"Amount Paid: $"<<sum_price<<endl;
}

//default destructor 
Card::~Card(){
 cout<<"Destroyed a Card object."<<endl;
}

//Subclass of Payment: Cash
//default Cash constructor
Cash::Cash(){
	change = 0;
	amount_paid = 0;
	method_name = "Cash";
}

//asks and stores the amount of cash paid by user 
void Cash::setAmountPaid(){
	cout<<"Enter the amount of cash paid: ";
	cin>>amount_paid;
	cout<<"\n";
}

double Cash::getAmountPaid(){
	return amount_paid;
}

void Cash::setPaymentInfo(){
	cout<<"You have chosen the cash payment option."<<endl;
	cout<<"Enter the amount of cash paid: ";
	cin>>amount_paid;

	while(amount_paid<sum_price){
		cout<<"\n"<<"Sorry the amount paid is insufficient"<<endl;
		cout<<"Your cart total to be paid is: $"<<sum_price<<endl;
		cout<<"Enter the amount of cash paid: ";
		cin>>amount_paid;
		cout<<"\n";
	}
}

void Cash::getPaymentInfo(){
	cout<<"Paid with: Cash"<<endl;
	cout<<"Amount Paid: $"<<amount_paid<<" Change received: $"<<getChange()<<endl;
}

double Cash::getChange(){
	change = amount_paid - sum_price;
	return change;
}

//default destructor 
Cash::~Cash(){
 cout<<"Destroyed a Cash object."<<endl;
}

//Subclass of Payment: LaterPay
//deafault LaterPay Constructor 
LaterPay::LaterPay(){
	installments_num = 0;
	price_per_installment = 0.0;
	exp_date = " ";
	card_name = " ";
	cvv = " ";
	card_name = " ";
	method_name = "LaterPay";
}

//asks and stores all info related to LaterPay payment method 
void LaterPay::setPaymentInfo(){
	double installments_num_double;
	cout<<"You have chosen the LaterPay payment option."<<endl;
	cout<<"Please enter your card details and installment options to complete payment."<<endl;
	cout<<"Cardholder Name: ";
	cin.ignore();
    getline(cin, card_name);
   
	cout<<"\n";
	cout<<"Card Number: ";
	cin.ignore();
    getline(cin, card_num);
    
    while(card_num.length()!=15){
    	cout<<"\n"<<"Invalid card number. Card number must contain 16 digits."<<endl;
    	cout<<"Please enter the Card Number again: ";
		cin.ignore();
	    getline(cin, card_num);
    }

	cout<<"\n";
	cout<<"Card Expiration Date: ";
	cin>>exp_date;
	cout<<"\n";

	cout<<"Three Digit CVV Code: ";
	cin.ignore();
    getline(cin, cvv);  
    if(cvv.length()!=3){
    	cout<<"\n"<<"Invalid cvv code. Cvv code must contain 3 digits."<<endl;
    	cout<<"Please enter your three digit cvv code again: ";
		cin.ignore();
	    getline(cin, cvv);
    	while(cvv.length()!=2){
    		cout<<"\n"<<"Invalid cvv code. Cvv code must contain 3 digits."<<endl;
	    	cout<<"Please enter your three digit cvv code again: ";
			cin.ignore();
		    getline(cin, cvv);
       }
    }  
	cout<<"\n";

	cout<<"Enter the number of installments you wish to pay in (2, 3, or 4): ";
	cin>>installments_num_double;
	installments_num = floor(installments_num_double);
	cout<<"\n";

	while(installments_num<2 || installments_num>4){
		cout<<"\n"<<"Invalid input. You can only pay in installments of 2, 3 or 4."<<endl;
		cout<<"Enter the number of installments you wish to pay in: ";
	    cin>>installments_num_double;
	    installments_num = floor(installments_num_double);
	}

//storing the last 4 digits of card number
	card_end_num[0] = card_num[11];  
	card_end_num[1] = card_num[12];
	card_end_num[2] = card_num[13];
	card_end_num[3] = card_num[14];
}

//displays payment method name and ending 4 digits of card
void LaterPay::getPaymentInfo(){
	cout<<"Paid with: LaterPay and Card ending in ";
 	cout<<card_end_num[0]<<card_end_num[1]<<card_end_num[2]<<card_end_num[3]<<endl;
 	cout<<"First Installment of "<<installments_num<<" installments paid";
 	cout<<" with price per installment of $"<<getPricePerInstallment()<<endl;
}

int LaterPay::getInstallmentsNum(){
	return installments_num;
}

double LaterPay::getPricePerInstallment(){
	price_per_installment = sum_price/installments_num;
	return price_per_installment;
}

//default destructor 
LaterPay::~LaterPay(){
	cout<<"Destroyed a LaterPay object."<<endl;
}





















