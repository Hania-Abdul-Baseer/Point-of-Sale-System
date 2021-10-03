#include "Product.h"
#include <string>
using namespace std;
//basic product constructor
Product::Product(){
	product_name = " ";
	product_code = 0;
	product_price = 0;
}

//Product constructor and can include name, product code and product stock quantity 
Product::Product(string name,int code,double price){
	product_name = name;
	product_code = code;
	product_price = price;
}

// product name getter and setter
string Product::getProductName(){
	return product_name;
}
void Product::setProductName(string name){
	product_name = name;
}

//set product price
void Product::setProductPrice(double price){
	product_price = price;
}

// product code getter and setter
int Product::getProductCode(){
	return product_code;
}
void Product::setProductCode(int code){
	product_code = code;
}

Product::~Product(){}

//PRODUCT SUBCLASS -> ITEMBYWEIGHT
// constructors for ItemByWeight subclass 
ItemByWeight::ItemByWeight(){
	product_name = " ";
	product_code = 0;
	product_price = 0;
	in_stock_quantity=0;
}
ItemByWeight::ItemByWeight(std::string name,int code,double price,double stock){
	product_name = name;
	product_code = code;
	product_price = price;
	in_stock_quantity = stock;
}

// gets the price of the product depending on the weight(kg) of the purchased
double ItemByWeight::getProductPrice(double quantity){
	quantity_required = quantity;
	return (quantity_required * product_price);
}

// gets and sets the weight (kg) of stock for the item
double ItemByWeight::getProductStock(){
	return in_stock_quantity;
}
void ItemByWeight::setProductStock(double stock){
	in_stock_quantity = stock;
}

//ItemByWeight destructor	
ItemByWeight::~ItemByWeight(){}

//PRODUCT SUBCLASS -> ITEMBYQUANTITY

// constructors for ItemByQuantity subclass 
ItemByQuantity::ItemByQuantity(){
	product_name = " ";
	product_code = 0;
	product_price = 0;
	in_stock_quantity=0;
}
ItemByQuantity::ItemByQuantity(std::string name,int code,double price,int stock){
	product_name = name;
	product_code = code;
	product_price = price;
	in_stock_quantity = stock;
}

// gets the price of the product depending on how many are purchased
double ItemByQuantity::getProductPrice(int quantity){
	quantity_required = quantity;
	return (quantity_required * product_price);
}

// gets and sets the number of stock for the item
double ItemByQuantity::getProductStock(){
	return in_stock_quantity;
}
void ItemByQuantity::setProductStock(int stock){
	in_stock_quantity = stock;
}

//ItemByQuantity destructor	
ItemByQuantity::~ItemByQuantity(){}
