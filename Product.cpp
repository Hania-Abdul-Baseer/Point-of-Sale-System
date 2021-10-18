#include "Product.h"
#include <string>
#include <math.h>
using namespace std;

//basic product constructor
Product::Product(){
	//intialise variables
	product_name = " ";
	product_code = 0;
	product_price = 0;
	quantity_required = 0;
	in_stock_quantity = 0;
	product_by_quantity = true;
}

//Product constructor and can include name, product code and product stock quantity 
Product::Product(std::string name,int code, double price,double stock,bool byQuantity){
	product_by_quantity = byQuantity;
	//this will be set by user therefore it is 0 as of now
	quantity_required = 0;
	product_name = name;
	product_code = code;
	in_stock_quantity = stock;

	//price can only be in 2 decimal points
	product_price = round(price*100)/100;

	// if there are only whole products then the stock is a whole number
	// this will ensure that if there are decimals in the answer it will become a whole number 
	if (product_by_quantity == true){
		in_stock_quantity = floor(stock);
	}
}

// product name getter and setter
string Product::getProductName(){
	return product_name;
}
void Product::setProductName(string name){
	if (name == "")
	{
		return;
	}
	product_name = name;
}

//set and get product price
void Product::setProductPrice(double price){
	if (price < 0)
	{
		return;
	}
	// price can only be a maximum of two decimal points
	product_price = ((round(price*100))/100);	
}
double Product::getProductPrice(){
	return((round((quantity_required * product_price)*100))/100);
}
double Product::getDefultProductPrice(){
	return product_price;
}

// product code getter and setter
int Product::getProductCode(){
	return product_code;
}
void Product::setProductCode(int code){
	if (code < 0)
	{
		return;
	}

	product_code = code;
}

// product stock getter and setter
// stock is in kg for 
double Product::getProductStock(){
	return in_stock_quantity;
}
void Product::setProductStock(double stock){
	if (stock < 0)
	{
		return;
	}
	if (product_by_quantity == true){
		in_stock_quantity = floor(stock);
	}
	else{
		in_stock_quantity = stock;
	}
}

// get and set the quantity of the product that the user desires 
double Product::getQuantityRequired(){
	return quantity_required;
}
void Product::setQuantityRequired(){
	// ask for product quantity required check if it meets the stock requirement
    int x = 0;
    double product_quantity_required =0;
    while(x == 0){
        //output to ask for the product quantity required and input of the requireed amount
        cout << "Enter the quantity of " << product_name <<" you would like to purchase: ";
        cin >> product_quantity_required;
        cout <<endl;

        // if it is by-quantity then the whole value is taken
        if (product_by_quantity == true)
		{
		product_quantity_required = floor(product_quantity_required);
		}

        // if it doesnt fit this conditions then it will exit while loop and the quantity requirement will be added to the product 
        if (!((in_stock_quantity - product_quantity_required) < 0 || product_quantity_required < 0))
        {
            quantity_required = quantity_required + product_quantity_required;
            in_stock_quantity = in_stock_quantity - product_quantity_required;
            x = 1;
        }
        // if the quantity required exceeds the product stock or the value is less than or equal to 0
        //it will display error message and the while loop will continue
        else{
            cout << "Error, invalid input, please enter the correct quantity."<<endl;
        }
    }
	
}

//set and get if the item is priced by-quantity or by-weight
// if it is by quantity then boolean is true
bool Product::getByQuantity(){
	return product_by_quantity;
}
void Product::setByQuanity(bool byQuantity){
	product_by_quantity = byQuantity;
}


Product::~Product(){}
