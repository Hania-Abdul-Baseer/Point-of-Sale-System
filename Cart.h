#include <iostream>
#include "Product.h"
using namespace std;

#ifndef CART_H
#define CART_H

//class Cart
class Cart{
public:
    //constructor
    Cart();

    //member functions
    void addProduct(Product new_item);
    void deleteProduct(Product unwanted_item);

    //destructor
    ~Cart();

private:
    //member variables
    Product* list;
    int count;
    double total_price;
    //member function
    double sumPrice(Product* list);
};
