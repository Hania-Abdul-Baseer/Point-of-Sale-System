ll: maintest

maintest: main.o
	./main.o

main.o: grocerysystem.cpp Receipt.o
	g++ -Wall grocerysystem.cpp Receipt.o -o main.o


test4: ReceiptTest.o
	./ReceiptTest

ReceiptTest.o: ReceiptTest.cpp Receipt.o Payment.o
	g++ -Wall ReceiptTest.cpp Receipt.o Payment.o -o ReceiptTest.o

Receipt.o: Receipt.cpp Receipt.h Payment.o
	g++ -Wall Receipt.cpp Payment.o -o Receipt.o

test3: PaymentTest.o
	./PaymentTest.o

PaymentTest.o: PaymentTest.cpp Payment.o Cart.o
	g++ -Wall PaymentTest.cpp Payment.o Cart.o -o PaymentTest.o

Payment.o: Payment.cpp Payment.h Cart.o
	g++ -Wall Payment.cpp Cart.o -o Payment.o

test2: CartTest.o
	./CartTest.o

CartTest.o: CartTest.cpp Cart.o Product.o
	g++ -Wall CartTest.cpp Cart.cpp Product.o -o CartTest.o

Cart.o: Cart.cpp Cart.h Product.o
	g++ -Wall Cart.cpp Product.cpp -o Cart.o

test1: ProductTest.o
	./ProductTest.o

ProductTest.o: ProductTest.cpp Product.o
	g++ -Wall ProductTest.cpp Product.o -o ProductTest.o

Product.o: Product.cpp Product.h
	g++ -Wall -c Product.cpp -o Product.o

clean:
	rm -f *.o all
