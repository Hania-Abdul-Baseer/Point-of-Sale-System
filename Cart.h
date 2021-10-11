#include "Product.h"
using namespace std;

#ifndef CART_H
#define CART_H

//class Cart
class Cart{
public:
    //constructor
    Cart();
    Cart(int inventory_size);

    //member functions
    void addProduct(Product new_item);
    double getTotalPrice();

    //public member variables
    Product* cart_list;
    int cart_count;

    //destructor
    ~Cart();

private:
    //member variables
    double total_price;
};
#endif

