
Receipt.o: Receipt.cpp Receipt.h
	g++ -Wall -c Receipt.cpp -o Receipt.o

Payment.o: Payment.cpp Payment.h
	g++ -Wall -c Payment.cpp -o Payment.o

Product.o: Product.cpp Product.h
	g++ -Wall -c Product.cpp -o Product.o

clean:
	rm -f *.o all
