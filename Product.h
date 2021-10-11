#include <iostream>
#include <string>
#ifndef PRODUCT_H
#define PRODUCT_H

class Product {
public:
	//Defult Constructors
	Product();
	//Constructor to enter product name, code, price and stock quantity
	Product(std::string name,int code, double price,double stock,bool byQuantity);

	//set and get product name
	std::string getProductName();
	void setProductName(std::string name);

	//set price and get price by entering the required quantity 
	double getProductPrice();
	double getDefultProductPrice();
	void setProductPrice(double price);

	// get and set product code
	int getProductCode();
	void setProductCode(int code);

	// get and set product stock 
	double getProductStock();
	void setProductStock(double stock);

	// get and set product quantity requirement 
	double getQuantityRequired();
	void setQuantityRequired();


	//is the iteam by quantity? 
	//getter and setter for this boolean
	bool getByQuantity();
	void setByQuanity(bool byQuantity);

	// product destructor
	~Product();

	// variables for price, name, code, quantity required and stock quantity 
	double product_price;
	std::string product_name;
	int product_code;
	double quantity_required;
	double in_stock_quantity;
	bool product_by_quantity;
};
#endif
