#include <iostream>
#include <string>
#include "Payment.h"
#include "Cart.h"
using namespace std;

int main(){

	cout<<"----------------------------Card unit test------------------------"<<endl;

	Card c1 = Card();
	c1.setPaymentInfo();

	cout<<"Expected card holder name: Hania Abdul Baseer. "<<"Actual card holder name: ";
	cout<<c1.card_name<<"\n\n";
	cout<<"Expected cvv number: 123. "<<"Actual cvv number: ";
	cout<<c1.cvv<<"\n\n";
	cout<<"Expected card expiry date: 12/12/12. "<<"Actual card expiry date: ";
	cout<<c1.exp_date<<"\n\n";
	cout<<"Expected ending card number: 3456. "<<"Actual ending card number: ";
	for(int i=0;i<4;i++){
		cout<<c1.card_end_num[i];
	}
	cout<<"\n\n";

	c1.getPaymentInfo();
	cout<<"\n\n";

	cout<<"----------------------------Cash unit test------------------------"<<endl;
	Cash ca1 = Cash();
	ca1.setPaymentInfo();
	cout<<"\n";
	cout<<"Expected Change: -"<<ca1.getAmountPaid()<<". "<<"Actual Change: "<<ca1.getChange()<<"\n\n";
	ca1.getPaymentInfo();
	cout<<"\n\n";

	cout<<"-------------------------LaterPay unit test--------------------------"<<endl;
	LaterPay l1 = LaterPay();
	l1.setPaymentInfo();
	cout<<"\n";

	cout<<"Expected card holder name: Hania Abdul Baseer. "<<"Actual card holder name: ";
	cout<<l1.card_name<<"\n\n";
	cout<<"Expected cvv number: 123. "<<"Actual cvv number: ";
	cout<<l1.cvv<<"\n\n";
	cout<<"Expected card expiry date: 12/12/12. "<<"Actual card expiry date: ";
	cout<<l1.exp_date<<"\n\n";
	cout<<"Expected number of installments: 4. "<<"Actual number of installments: ";
	cout<<l1.installments_num<<"\n\n";
	cout<<"Expected ending card number: 3456. "<<"Actual ending card number: ";
	for(int i=0;i<4;i++){
		cout<<l1.card_end_num[i];
	}
	cout<<"\n\n";
	cout<<"Expected price per installment: 0. "<<"Actual price per installment: "<<l1.getPricePerInstallment()<<"\n\n";

	l1.getPaymentInfo();
	cout<<"\n\n";

	return 0;
}
