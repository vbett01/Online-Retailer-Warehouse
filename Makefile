CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -std=c++11
LDFLAGS  = -g3

proj1: main.o OrderQueue.o Parser.o Packer.o incomingOrders.o Fetcher.o string2int.o
	${CXX} ${LDFLAGS} -o proj1 main.o OrderQueue.o Parser.o Packer.o incomingOrders.o Fetcher.o string2int.o
	
	
OrderQueue.o: OrderQueue.cpp OrderQueue.h Order.h
Parser.o: Parser.cpp Parser.h Order.h
Packer.o: Packer.cpp Packer.h OrderQueue.h Order.h
incomingOrders.o: incomingOrders.cpp incomingOrders.h OrderQueue.h Order.h
Fetcher.o: Fetcher.cpp Fetcher.h OrderQueue.h Order.h
string2int.o: string2int.cpp string2int.h



clean:
	rm -rf proj1 *.o *.dSYM
 
