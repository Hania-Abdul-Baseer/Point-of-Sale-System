#include "Cart.h"
#include <math.h>

//default Cart constructor
Cart::Cart(){
    cart_list = new Product[0];
    cart_count = 0;
    total_price = 0;
}

//constructor with cart list size
Cart::Cart(int inventory_size){
    cart_list = new Product[inventory_size];
    cart_count = 0;
    total_price = 0;
}

//adding product to the list
void Cart::addProduct(Product item){

    // this variable is equal to the amount of items in the array
    //this ensures that the for-loop will end even if cart_count is added to
    int index = cart_count;

    // check if the quantity reqruied/added for this product is 0 or less
    if (!(item.getQuantityRequired() > 0)){
        // if it is then this function will end
        return;
    }

    // if its the first item in the cart then it will be added to the cart_list
    if (cart_count == 0){
        cart_list[cart_count++] = item;
    }
    else{
        int count = 0; // will count if the same product is already in the cart_list

        // if loop to check if the item is in the cart array
        for (int i = 0; i < index; ++i){
            if (cart_list[i].getProductCode() == item.getProductCode()){
                // if the product is in the cart list it will be updated with the new item
                cart_list[i] = item;
                count = count +1; // will be added to
            }
        }

        // if it isnt in the cart_list it will be added to the cart list
        if (count == 0){
            cart_list[cart_count++] = item;
        }
    }

}

// get the total price of products in the cart
double Cart::getTotalPrice(){
    //Will ensure that total price doesnt accumulate as the function is called
    total_price = 0;
    // will loop through the cart list and get the product price
    for (int i = 0; i < cart_count; ++i){
        // product price will be added to the total price
        total_price = total_price + cart_list[i].getProductPrice();
    }

    return total_price;// total price for products in cart  is returned
}

// get the list of products
Product* Cart::getCartList(){
    return cart_list;
}

//destructor
Cart::~Cart(){
    delete[] cart_list;
}
