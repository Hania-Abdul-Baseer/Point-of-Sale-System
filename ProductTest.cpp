#include <iostream>
#include "Product.h"
using namespace std;

int main(){

	//TESTING getter and setter for ProductName 
	//Normal inputs
	{
		Product p1;
		p1.setProductName("Apples");
		
		if (!(p1.getProductName() == "Apples"))
		{
			cout << "1.This is an incorrect output. Consider revising code for this function." <<endl;
		}
	}
	//testing no input should ouput defult product name
	{
		Product p1;
		p1.setProductName("");
		if (!(p1.getProductName() == " "))
		{
			cout << "2.This is an incorrect output. Consider revising code for this function." <<endl;
		}
	}
	


	// TESTING getter and setter for ProductCode
	//Normal inputs
	{
		Product p1;
		p1.setProductCode(19);
		
		if (!(p1.getProductCode() == 19))
		{
			cout << "3.This is an incorrect output. Consider revising code for this function." <<endl;
		}
	}
	//0 input
	{
		Product p1;
		p1.setProductCode(0);
		
		if (!(p1.getProductCode() == 0))
		{
			cout << "4.This is an incorrect output. Consider revising code for this function." <<endl;
		}
	}
	//Negative input should return defult output
	{
		Product p1;
		p1.setProductCode(-200);
		
		if (!(p1.getProductCode() == 0))
		{
			cout << "5.This is an incorrect output. Consider revising code for this function." <<endl;
		}
	}



	// TESTING getter and setter for ProductStock 
	//Normal inputs
	{
		Product p1("Apples",3,2.00,50,false);
		p1.setProductStock(19.5);
		
		if (!(p1.getProductStock() == 19.5))
		{
			cout << "6.This is an incorrect output. Consider revising code for this function." <<endl;
		}
	}
	//As its by quantity the value cannot be a decimal so it will be rounded down
	{
		Product p1("Apples",3,2.00,50,true);
		p1.setProductStock(19.5);
		if (!(p1.getProductStock() == 19))
		{
			cout << "7.This is an incorrect output. Consider revising code for this function." <<endl;
		}
	}
	//Cannot be negative value, therefore should be defult stock value
	{
		Product p1("Apples",3,2.00,50,false);
		p1.setProductStock(-200);
		
		if (!(p1.getProductStock() == 50))
		{
			cout << "8.This is an incorrect output. Consider revising code for this function." <<endl;
		}
	}
	// Stock can be 0
	{
		Product p1("Apples",3,2.00,50,false);
		p1.setProductStock(0);
		
		if (!(p1.getProductStock() == 0))
		{
			cout << "9.This is an incorrect output. Consider revising code for this function." <<endl;
		}
	}



	// TESTING getter and setter for ByQuanity
	//Normal input (true)
	{
		Product p1;
		p1.setByQuanity(true);
		
		if (!(p1.getByQuantity() == 1))
		{
			cout << "10.This is an incorrect output. Consider revising code for this function." <<endl;
		}
	}
	//Normal input (false)
	{
		Product p1;
		p1.setByQuanity(false);
		
		if (!(p1.getByQuantity() == 0))
		{
			cout << "11.This is an incorrect output. Consider revising code for this function." <<endl;
		}
	}
	//any other inputs shoudl result in true
	{
		Product p1;
		p1.setByQuanity(10);
		
		if (!(p1.getByQuantity() == 1))
		{
			cout << "12.This is an incorrect output. Consider revising code for this function." <<endl;
		}
	}



	// TESTING getter and setter for defult ProductPrice
	//Normal inputs
	{
		Product p1;
		p1.setProductPrice(12.57);

		if (!(p1.getDefultProductPrice() == 12.57))
		{
			cout << "13.This is an incorrect output. Consider revising code for this function." <<endl;
		}
	}
	//the price should be in maximum 2 decimal spaces, if not it will be rounded
	{
		Product p1;
		p1.setProductPrice(12.5754);

		if (!(p1.getDefultProductPrice() == 12.58))
		{
			cout << "14.This is an incorrect output. Consider revising code for this function." <<endl;
		}
	}
	// the price cannot be negative so it will 
	{
		Product p1;
		p1.setProductPrice(-67);

		if (!(p1.getDefultProductPrice() == 0))
		{
			cout << "15.This is an incorrect output. Consider revising code for this function." <<endl;
		}
	}
	// the price can be 0
	{
		Product p1;
		p1.setProductPrice(0);

		if (!(p1.getDefultProductPrice() == 0))
		{
			cout << "16.This is an incorrect output. Consider revising code for this function." <<endl;
		}
	}



	// TESTING getter and setter for QuantityRequired
	//Normal input (set to 5)
	{
		Product p1("Apples",3,2.00,50,false);
		p1.setQuantityRequired();
		cout << p1.getQuantityRequired()<<endl;
	}
	//test negative values it should ask for another valid input(set to -30 and then 5)
	{
		Product p1("Apples",3,2.00,50,false);
		p1.setQuantityRequired();
		cout << p1.getQuantityRequired()<<endl;
	}
	//test values out of stock range it should ask for another valid input(set to 100 and then 5)
	{
		Product p1("Apples",3,2.00,50,false);
		p1.setQuantityRequired();
		cout << p1.getQuantityRequired()<<endl;
	}
	//test if the whole stock can be purchased (set to 50)
	{
		Product p1("Apples",3,2.00,50,false);
		p1.setQuantityRequired();
		cout << p1.getQuantityRequired()<<endl;
	}
	//test if the quantity can be added to by calling function twice (set to 5 and 7)
	{
		Product p1("Apples",3,2.00,50,false);
		p1.setQuantityRequired();
		p1.setQuantityRequired();
		cout << p1.getQuantityRequired()<<endl;
	}
	//test if value is being rounded for items by quantity (set to 5.5)
	{
		Product p1("Apples",3,2.00,50,true);
		p1.setQuantityRequired();
		cout << p1.getQuantityRequired()<<endl;
	}

	return 0;
}
