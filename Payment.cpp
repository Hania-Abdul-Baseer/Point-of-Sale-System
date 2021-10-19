#include <iostream>
#include <string>
#include <cmath>
#include "Payment.h"
#include "Cart.h"
#include "ctype.h"
using namespace std;

bool isNumber2(string str){

	int len1 = str.length();
	for(int i=0;i<len1;i++){
		if(isdigit(str[i]) ==0){
			return false;
		}
	}
	return true;
}

bool isDouble(string str){
	int len2 = str.length();

		for(int i=0;i<len2;i++){
			if((isdigit(str[i]) == 0) && (str[i] != '.')){
				return false;
			}
		}
		return true;
}

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

	cout<<"\nYou have chosen the card payment method."<<endl;
	cout<<"Please enter your card details to complete payment"<<endl;
	cout<<"Cardholder Name: ";
	cin.ignore();
    getline(cin, card_name);
	cout<<"\n";

	cout<<"Card Number: ";
	cin.ignore();
    getline(cin, card_num);

    while((isNumber2(card_num))==false || (card_num.length()!=15)){
    	cout<<"\n"<<"Invalid card number. Card number must contain 16 digits."<<endl;
    	cout<<"Please enter the Card Number again: ";
		cin.ignore();
	    getline(cin, card_num);
    }
	cout<<"\n";

	cout<<"Card Expiration Date in format (dd/mm/yyyy): ";
	cin.ignore();
    getline(cin, exp_date);
    if(exp_date.length()!=9){
    	cout<<"Invalid input. Card expiration date must follow the dd/mm/yyyy format."<<endl;
		cout<<"Please enter your card expiration date again: ";
	    cin>>exp_date;
	while(exp_date.length()!=10){
		cout<<"Invalid input. Card expiration date must follow the dd/mm/yyyy format."<<endl;
		cout<<"Please enter your card expiration date again: ";
	    cin>>exp_date;
	}
  }
	cout<<"\n";

	cout<<"Three Digit CVV Code: ";
	cin>>cvv;

    	while((isNumber2(cvv))==false || (cvv.length()!=3)){
    		cout<<"\n"<<"Invalid cvv code. Cvv code must contain 3 digits."<<endl;
	    	cout<<"Please enter your three digit cvv code again: ";
			cin>>cvv;
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
 	cout<<"\n";
}

//default destructor
Card::~Card(){
}

//Subclass of Payment: Cash
//default Cash constructor
Cash::Cash(){
	change = 0;
	amount_paid = 0.0;
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
	string amount_paid_str = " ";

	cout<<"\nYou have chosen the cash payment option."<<endl;
	cout<<"Enter the amount of cash paid: ";
	cin>>amount_paid_str;

	if(isDouble(amount_paid_str) == true){
		amount_paid = stod(amount_paid_str);
	}

	while(isDouble(amount_paid_str) == false || amount_paid<sum_price){

		if(isDouble(amount_paid_str) == false){
			cout<<"\n"<<"Error! Invalid Input"<<endl;
			cout<<"Your cart total to be paid is: $"<<sum_price<<endl;
			cout<<"Enter the amount of cash paid: ";
			cin>>amount_paid_str;

			if(isDouble(amount_paid_str) == true){
			amount_paid = stod(amount_paid_str);
			}

			cout<<"\n";
		}

		else{
			cout<<"\n"<<"Sorry the amount paid is insufficient"<<endl;
			cout<<"Your cart total to be paid is: $"<<sum_price<<endl;
			cout<<"Enter the amount of cash paid: ";
			cin>>amount_paid_str;

			if(isDouble(amount_paid_str) == true){
			amount_paid = stod(amount_paid_str);
			}

			cout<<"\n";
		}
	}

	amount_paid = stod(amount_paid_str);
	cout<<"\n";

	/*string amount_paid_str = " ";
	cout<<"\nYou have chosen the cash payment option."<<endl;
	cout<<"Enter the amount of cash paid: ";
	cin>>amount_paid_str;
	if(isNumber2(amount_paid_str) == true){
		amount_paid = stod(amount_paid_str);
	}
	while(isNumber2(amount_paid_str) ==false || amount_paid<sum_price){
		if(amount_paid<sum_price){
			cout<<"\n"<<"Sorry the amount paid is insufficient"<<endl;
			cout<<"Your cart total to be paid is: $"<<sum_price<<endl;
			cout<<"Enter the amount of cash paid: ";
			cin>>amount_paid_str;
			amount_paid = stod(amount_paid_str);
			cout<<"\n";
		}
		else{
			cout<<"\n"<<"Error! Invalid Input"<<endl;
			cout<<"Your cart total to be paid is: $"<<sum_price<<endl;
			cout<<"Enter the amount of cash paid: ";
			cin>>amount_paid_str;
			cout<<"\n";
		}
	}
	amount_paid = stod(amount_paid_str);
	cout<<"\n";*/
}

void Cash::getPaymentInfo(){
	cout<<"Paid with: Cash"<<endl;
	cout<<"Amount Paid: $"<<amount_paid<<" Change received: $"<<getChange()<<endl;
	cout<<"\n";
}

double Cash::getChange(){
	change = amount_paid - sum_price;
	return change;
}

//default destructor
Cash::~Cash(){
}

//Subclass of Payment: LaterPay
//deafault LaterPay Constructor
LaterPay::LaterPay(){
	installments_num = 0;
	installments_num_str = " ";
	price_per_installment = 0.0;
	exp_date = " ";
	card_name = " ";
	cvv = " ";
	card_name = " ";
	method_name = "LaterPay";
}

//asks and stores all info related to LaterPay payment method
void LaterPay::setPaymentInfo(){
	cout<<"\nYou have chosen the LaterPay payment option."<<endl;
	cout<<"Please enter your card details and installment options to complete payment."<<endl;
	cout<<"Cardholder Name: ";
	cin.ignore();
    getline(cin, card_name);
   	cout<<"\n";

	cout<<"Card Number: ";
	cin.ignore();
    getline(cin, card_num);
    while((isNumber2(card_num))==false || (card_num.length()!=15)){
    	cout<<"\n"<<"Invalid card number. Card number must contain 16 digits."<<endl;
    	cout<<"Please enter the Card Number again: ";
		cin.ignore();
	    getline(cin, card_num);
    }
	cout<<"\n";

	cout<<"Card Expiration Date in format (dd/mm/yyyy): ";
	cin.ignore();
    getline(cin, exp_date);
    if(exp_date.length()!=9){
    	cout<<"Invalid input. Card expiration date must follow the dd/mm/yyyy format."<<endl;
		cout<<"Please enter your card expiration date again: ";
	    cin>>exp_date;
	while(exp_date.length()!=10){
		cout<<"Invalid input. Card expiration date must follow the dd/mm/yyyy format."<<endl;
		cout<<"Please enter your card expiration date again: ";
	    cin>>exp_date;
	}
  }
	cout<<"\n";

	cout<<"Three Digit CVV Code: ";
	cin>>cvv;

    	while((isNumber2(cvv))==false || (cvv.length()!=3)){
    		cout<<"\n"<<"Invalid cvv code. Cvv code must contain 3 digits."<<endl;
	    	cout<<"Please enter your three digit cvv code again: ";
			cin>>cvv;
       }
	cout<<"\n";

	cout<<"Enter the number of installments you wish to pay in (2, 3, or 4): ";
	cin>>installments_num_str;
	cout<<"\n";

	while((isNumber2(installments_num_str)==false) || ((installments_num_str != "2") && (installments_num_str != "3") && (installments_num_str != "4"))){
		cout<<"\n"<<"Invalid input. You can only pay in installments of 2, 3 or 4."<<endl;
		cout<<"Enter the number of installments you wish to pay in: ";
	    cin>>installments_num_str;
	}

	if(installments_num_str == "2"){
		installments_num = 2;
	}
	if(installments_num_str == "3"){
		installments_num = 3;
	}
	if(installments_num_str == "4"){
		installments_num = 4;
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
	cout<<"\n";
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
}























