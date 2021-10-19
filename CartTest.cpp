#include <iostream>
#include "Product.h"
#include "Cart.h"

using namespace std;

int main(){
	// TESTING addProduct Function 
	{
		Cart cart1(1);
		Product apples("Apples (Royal Gala)",3,2.00,50,false);

		//input amount required as 5
		// should be the first element in the array and have amount 5 
		apples.setQuantityRequired();
		cart1.addProduct(apples);

		cout<< "1" <<endl;
		//display the cart -> product name and the quanityt required
		for (int i = 0; i < cart1.cart_count; ++i)
		{
			cout << cart1.cart_list[i].getProductName()<< "\t Quanity Required is:" <<  cart1.cart_list[i].getQuantityRequired() <<endl;
		}
		
	}
	{
		Cart cart1(1);
		Product apples("Apples (Royal Gala)",3,2.00,50,false);

		//input amount required as 5
		// should be the first element in the array 
		apples.setQuantityRequired();
		cart1.addProduct(apples);

		// ensure that when the product is added again it doesnt add onto the array again
		// it should only increase in quanity
		//input amount required as 7
		// should display 12
		apples.setQuantityRequired();
		cart1.addProduct(apples);
		cout<< "2" <<endl;
		for (int i = 0; i < cart1.cart_count; ++i)
		{
			cout << cart1.cart_list[i].getProductName()<< "\t Quanity Required is:" <<  cart1.cart_list[i].getQuantityRequired() <<endl;
		}
	}
	{
		Cart cart1(2);
		Product apples("Apples (Royal Gala)",3,2.00,50,false);
		Product strawberries("Strawberries 250g punnet",5,1.50,30,true);

		//input amount required as 2
		// should be the first element in the array 
		apples.setQuantityRequired();
		cart1.addProduct(apples);

		// input amount 1 
		// should be the second element in the array
		strawberries.setQuantityRequired();
		cart1.addProduct(strawberries);

		//input amount 2
		//should not increase the elements in the array only the quanity
		strawberries.setQuantityRequired();
		cart1.addProduct(strawberries);

		cout<< "3" <<endl;
		for (int i = 0; i < cart1.cart_count; ++i)
		{
			cout << cart1.cart_list[i].getProductName()<< "\t Quanity Required is:" <<  cart1.cart_list[i].getQuantityRequired() <<endl;
		}
	}


	// TESTING getTotalPrice Function 
	{
		Cart cart1(1);
		Product apples("Apples (Royal Gala)",3,2.00,50,false);

		//input amount required as 5
		// should be the first element in the array and have amount 5 
		apples.setQuantityRequired();
		cart1.addProduct(apples);

		cout<< endl << "4" <<endl;

		// single item in cart therefore should be $10
		cout << "$" << cart1.getTotalPrice() <<endl;

		
	}
	{
		Cart cart1(2);
		Product apples("Apples (Royal Gala)",3,2.00,50,false);
		Product strawberries("Strawberries 250g punnet",5,1.50,30,true);

		//input amount required as 2
		apples.setQuantityRequired();
		cart1.addProduct(apples);

		// input amount 1 
		strawberries.setQuantityRequired();
		cart1.addProduct(strawberries);

		//input amount 2
		strawberries.setQuantityRequired();
		cart1.addProduct(strawberries);

		cout<< "5" <<endl;

		// multiple items in cart therefore should be (2*2 + 1.50*3) = $8.50
		cout << "$" << cart1.getTotalPrice() <<endl;
		
		// calling twice because it should duplicate the price (it should remain as $8.50)
		cout << "$" << cart1.getTotalPrice() <<endl;
	}

	return 0;
}
