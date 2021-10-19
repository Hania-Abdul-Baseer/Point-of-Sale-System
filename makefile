all: maintest

maintest: main
	./main < maininput.txt > mainoutput.txt
	diff mainoutput.txt maincheck.txt

main: grocerysystem.cpp
	g++ -Wall grocerysystem.cpp Product.cpp Cart.cpp Payment.cpp Receipt.cpp -o main

test4: Receipt.h Receipt.cpp Payment.h Payment.cpp Cart.h Cart.cpp Product.h Product.cpp
	g++ -Wall ReceiptTest.cpp Receipt.cpp Payment.cpp Cart.cpp Product.cpp -o ReceiptTest
	./ReceiptTest
	diff ReceiptTestOutput.txt ReceiptTestCheck.txt

test3: Payment.h Payment.cpp Cart.h Cart.cpp Product.h Product.cpp
	g++ -Wall PaymentTest.cpp Payment.cpp Cart.cpp Product.cpp -o PaymentTest
	./PaymentTest < PaymentTestInput.txt | diff - PaymentTestCheck.txt


test2: Cart.h Cart.cpp Product.h Product.cpp
	g++ -Wall CartTest.cpp Cart.cpp Product.cpp -o CartTest
	./CartTest < CartTestInputs.txt | diff - CartTestOuput.txt


test1: Product.h Product.cpp
	g++ -Wall ProductTest.cpp Product.cpp -o ProductTest
	./ProductTest < ProductTestInputs.txt |diff - ProductTestOutput.txt 
	
clean: 
	rm -f *.o main all
