#include <iostream>
#include <string>
#include "Payment.h"
#include "Cart.h"
using namespace std;

int main(){
	cout<<"------------------------------Card unit test-----------------------------"<<endl;
	Card c1 = Card();
	c1.setPaymentInfo();
	c1.getPaymentInfo();

	Card c2 = Card();
	c2.setPaymentInfo();
	c2.getPaymentInfo();

	cout<<"-------------------------------Cash unit test------------------------------"<<endl;
	Cash ca1 = Cash();
	ca1.sum_price = 31.4;
	ca1.setPaymentInfo();
	ca1.getPaymentInfo();

	Cash ca2 = Cash();
	ca2.sum_price = 143.43;
	ca2.setPaymentInfo();
	ca2.getPaymentInfo();
	
	cout<<"----------------------------LaterPay unit test-----------------------------"<<endl;
	//checking installments of 2
	LaterPay l1 = LaterPay();
	l1.sum_price = 325.65;
	l1.setPaymentInfo();
	l1.getPaymentInfo();

	//checking installments of 3
	LaterPay l2 = LaterPay();
	l2.sum_price = 325.65;
	l2.setPaymentInfo();
	l2.getPaymentInfo();

	//checking installments of 4
	LaterPay l3 = LaterPay();
	l3.sum_price = 325.65;
	l3.setPaymentInfo();
	l3.getPaymentInfo();

	//checking other invalid inputs
	LaterPay l4 = LaterPay();
	l4.sum_price = 325.65;
	l4.setPaymentInfo();
	l4.getPaymentInfo();

	return 0;
}

