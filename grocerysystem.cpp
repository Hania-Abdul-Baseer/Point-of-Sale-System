#include <iostream>
#include "Product.h"
#include "Cart.h"
#include "Payment.h"
#include "Receipt.h"
using namespace std;

int main(){

	// FIRST STEP: DISPLAY INVENTORY, SELECT ITEMS AND ADD TO CART
	//output a welcome for the user
	cout << "Welcome to Best Buy Grocery Store!" << endl;

	//created a dynamic array to store the inventory
	int inventory_size = 18; //size of the array
	int inventory_index = 0;
	//inventory array of object products
	Product *inventory = new Product[inventory_size];

	//create a cart object to store customer selection and the total price
	Cart c1(inventory_size);

	//Entered and intialise the products in the shop
	//add them to a dynamic array called inventory
	Product watermelons("Watermelons",1,2.00,140,false);
	inventory[inventory_index++] = watermelons;
	Product mangoes("Mangoes",2,3,50,true);
	inventory[inventory_index++] = mangoes;
	Product apples("Apples (Royal Gala)",3,2.00,50,false);
	inventory[inventory_index++] = apples;
	Product bananas("Bananas",4,3.00,25,false);
	inventory[inventory_index++] = bananas;
	Product strawberries("Strawberries 250g punnet",5,1.50,30,true);
	inventory[inventory_index++] = strawberries;
	Product pears("Pears",6,2.00,30,false);
	inventory[inventory_index++] = pears;
	Product oranges("Oranges 3kg bags",7,5.50,20,true);
	inventory[inventory_index++] = oranges;
	Product pineapples("Pineapples (whole)",8,3.00,20,true);
	inventory[inventory_index++] = pineapples;
	Product rockmelons("RockMelons (whole)",9,3.00,20,true);
	inventory[inventory_index++] = rockmelons;

	Product salad("Salad Mix 200g bag",10,2.00,15,true);
	inventory[inventory_index++] = salad;
	Product cucumbers("Cucumber 250g bag",11,2.50,30,true);
	inventory[inventory_index++] = cucumbers;
	Product carrots("Carrots 1kg bag",12,2.00,20,true);
	inventory[inventory_index++] = carrots;
	Product tomatoes("Tomatoes",13,5.00,15,false);
	inventory[inventory_index++] = tomatoes;
	Product	capcicums("Capcicums",14,5.00,20,false);
	inventory[inventory_index++] = capcicums;
	Product	onions("Red Onions",15,5.00,20,false);
	inventory[inventory_index++] = onions;
	Product potatoes("Potatoes 1kg bag",16,3.00,15,true);
	inventory[inventory_index++] = potatoes;
	Product mushrooms("Mushrooms",17,7.00,10,false);
	inventory[inventory_index++] = mushrooms;
	Product ginger("Ginger",18,15.00,10,false);
	inventory[inventory_index++] = ginger;


	//display the inventory for the uset
	for (int i = 0; i < 18; ++i){
		cout << inventory[i].getProductCode() << "." << inventory[i].getProductName() << " $" <<inventory[i].getDefultProductPrice();
		if (inventory[i].getByQuantity() == true){
			cout << " each" <<endl;
		}
		else{
			cout<< "/" <<"kg" <<endl;
		}
	}

	// customer will select item/s and will be presented with the option to proceed to payment
	int x = 0; // while loop condition variable

	// while loop will continue until the payment option is choosen
	while(x==0){
		x = 0;
		int input = -1; // will store the input value
		int count = 0;


		cout << endl <<"Select a product from the options above." <<endl;

		//when total price isnt zero the payment option will be displayed
		if (!(c1.getTotalPrice() == 0)){
			cout << "Enter a number from the options above and press Enter." <<endl;
			cout << "Or if you would like to proceed to payment, input ‘0’ and press enter. ";
		}
		//else the option to choose a product is displayed
		else{
			cout << "Enter a number from the options above and press Enter.";
		}

		// the user will input from the options shown
		cin >> input;

		//According to the input one of three options will be done

		for (int i = 0; i < inventory_size; ++i){
			//If the input is equal to any product in the inventory the following will occur
			if (input == inventory[i].getProductCode()){
				// user will be set the quanity required
				inventory[i].setQuantityRequired();
				// the item will be added to the cart
    			c1.addProduct(inventory[i]);
    			// this will ensure that the other options are ignored
    			count = 1;
			}
		}

		// if the input is 0 and there is something in the cart
		//then the user wants to continue to payment
		if (!(c1.getTotalPrice() == 0 ) && input == 0){
				x = 1; // will break out of while loop to continue to payment
				count = 1;
		}
		// if the options above werent executed then the input is invalid
		if(!(count == 1 )){
			// display that the input is invalid and redo while loop
			cout << endl <<"Error, invalid input. ";
		}
	}

	//END OF FIRST STEP

	//start here for payment



	//LAST STEP: PRINT RECEIPT AND SEND RECEIPT TO USER
	//set receipt number
	int receipt_no = 0000;
	//Prompt for preference of receiving the receipt
	cout << "Please select how you would like to receive your receipt:\n1.Email\n2.Phone number\n3.None of the above\nEnter a number from the options above and press Enter:" << endl;
    //store preference number
    int prefer_num;

    //check for valid input
    bool valid_input = false;
    while (valid_input == false){

        //prompt preference number
        cin >> prefer_num;

    	//check for valid input and create Receipt
        if (prefer_num == 1){
            ReceiptByEmail r1(cart_list, inventory_size, total_price, method, receipt_no);
            r1.getDetails();
            r1.notify();
            valid_input = true;
        }
        else if (prefer_num == 2){
            ReceiptByMessage r1(cart_list, inventory_size, total_price, method, receipt_no);
            r1.getDetails();
            r1.notify();
            valid_input = true;
        }
        else if (prefer_num == 3){
            Receipt r1(cart_list, inventory_size, total_price, method, receipt_no);
            valid_input = true;
        }
        else {
            cout << "Error! Please enter the number that specify your choice." << endl;
        }
    }

    //print receipt
    //receipt heading
    cout << "\n\n Best Buy Grocery Store\naddress\nwebsite\nphone number\nemail address\nABN\nTAX INVOICE\nReceipt no.: " << r1.getReceiptNo() << "\nDate/Time -- " << r1.getDateTime() << endl;
    //product info
    for(int i = 0; i < inventory_size; i++){
        cout <<
    }

    //payment info


    //extra info
    cout << "Exchange and refund will not be available.\nThank you for shopping at Good Buy Grocery Store." << endl;

    return 0;
}
