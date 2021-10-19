all: maintest

maintest2: main
	./main < maintestinput2.txt > maintestoutput2.txt
	diff maintestoutput2.txt maintestcheck2.txt

main: grocerysystem.cpp
	g++ -Wall grocerysystem.cpp Product.cpp Cart.cpp Payment.cpp Receipt.cpp -o main

test4: Receipt.h Receipt.cpp Payment.h Payment.cpp Cart.h Cart.cpp Product.h Product.cpp
	g++ -Wall ReceiptTest.cpp Receipt.cpp Payment.cpp Cart.cpp Product.cpp -o ReceiptTest
	./ReceiptTest < ReceiptTestInput.txt > ReceiptTestOutput.txt
	diff ReceiptTestOutput.txt ReceiptTestCheck.txt

test3: Payment.h Payment.cpp Cart.h Cart.cpp Product.h Product.cpp
	g++ -Wall PaymentTest.cpp Payment.cpp Cart.cpp Product.cpp -o PaymentTest
	./PaymentTest < PaymentTestInput.txt | diff - PaymentTestCheck.txt


test2: Cart.h Cart.cpp Product.h Product.cpp
	g++ -Wall CartTest.cpp Cart.cpp Product.cpp -o CartTest
	./CartTest < CartTestInput.txt | diff - CartTestCheck.txt


test1: Product.h Product.cpp
	g++ -Wall ProductTest.cpp Product.cpp -o ProductTest
	./ProductTest < ProductTestInput.txt |diff - ProductTestCheck.txt

clean:
	rm -f *.o main all
