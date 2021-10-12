all: maintest

maintest: main
	./main

main: grocerysystem.cpp Receipt.o
	g++ -Wall grocerysystem.cpp Product.o Cart.o Payment.o Receipt -o main

test4: ReceiptTest
	./ReceiptTest

ReceiptTest: ReceiptTest.cpp Receipt.o Payment.o
	g++ -Wall ReceiptTest.cpp Receipt.o Payment.o -o ReceiptTest

Receipt.o: Receipt.cpp Receipt.h Payment.o
	g++ -Wall Receipt.cpp Payment.o 

test3: PaymentTest
	./PaymentTest

PaymentTest: PaymentTest.cpp Payment.o
	g++ -Wall PaymentTest.cpp Product.o Cart.o Payment.o -o PaymentTest

Payment.o: Payment.h Payment.cpp Cart.o
	g++ -Wall -c Payment.cpp Cart.o

test2: CartTest
	./CartTest

CartTest: CartTest.cpp Cart.o Product.o
	g++ -Wall CartTest.cpp Cart.cpp Product.o -o CartTest

Cart.o: Cart.h Cart.cpp Product.o
	g++ -Wall -c Cart.cpp Product.o

test1: ProductTest
	./ProductTest

ProductTest: ProductTest.cpp Product.o
	g++ -Wall ProductTest.cpp Product.o -o ProductTest

Product.o: Product.h Product.cpp
	g++ -Wall -c Product.cpp  

clean:
	rm -f *.o all


