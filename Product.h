#include <iostream>
#include <string>
#ifndef PRODUCT_H
#define PRODUCT_H
#ifndef ITEMBYWEIGHT_H
#define ITEMBYWEIGHT_H
#ifndef ITEMBYQUANTITY_H
#define ITEMBYQUANTITY_H

class Product {
public:
	Product();
	Product(std::string name,int code, double price);

	std::string getProductName();
	void setProductName(std::string name);
	virtual double getProductPrice()=0;
	void setProductPrice(double price);
	int getProductCode();
	void setProductCode(int code);
	virtual double getProductStock()=0;
	virtual void setProductStock()=0;

	~Product();

	// variables
	double product_price;
	std::string product_name;
	int product_code;
};
#endif

class ItemByWeight: public Product{
public:
	ItemByWeight();
	ItemByWeight(std::string name,int code,double price,double stock);

	virtual double getProductPrice(double quantity);
	virtual double getProductStock();
	virtual void setProductStock(double stock);

	//variables
	double quantity_required;
	double in_stock_quantity;

	~ItemByWeight();
};
#endif

class ItemByQuantity: public Product{
public:
	ItemByQuantity();
	ItemByQuantity(std::string name,int code,double price,int stock);

	virtual double getProductPrice(int quantity);
	virtual double getProductStock();
	virtual void setProductStock(int stock);

	//variables
	int quantity_required;
	int in_stock_quantity;

	~ItemByQuantity();
};
#endif