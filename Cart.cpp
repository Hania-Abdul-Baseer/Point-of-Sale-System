#include "Cart.h"

//default Cart constructor
Cart::Cart(){
    Product* list = nullptr;
    int count = 0;
    double total_price = 0;
}

//adding product to the list
bool Cart::addProduct(Product new_item){

}

//deleting product from the list
void Cart::deleteProduct(Product unwanted_item){

}

//calculate the total price
double Cart::sumPrice(Product* list){
    for(int i = 0; i < count; i++){
        
    }
}

//destructor
Cart::~Cart(){
    delete[] list;
}
