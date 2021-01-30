main: main.cpp CreditConsultant.o
	g++ -o main main.cpp CreditConsultant.o BigBank.o MiddleBank.o SmallBank.o Bank.o -I.

CreditConsultant.o: CreditConsultant.cpp CreditConsultant.h SmallBank.o MiddleBank.o BigBank.o
	g++ -c CreditConsultant.cpp

BigBank.o: BigBank.cpp BigBank.h Bank.o
	g++ -c BigBank.cpp

MiddleBank.o: MiddleBank.cpp MiddleBank.h Bank.o
	g++ -c MiddleBank.cpp

SmallBank.o: SmallBank.cpp SmallBank.h Bank.o
	g++ -c SmallBank.cpp

Bank.o: Bank.cpp Bank.h
	g++ -c Bank.cpp

clean:
	-rm main
	-rm *.o