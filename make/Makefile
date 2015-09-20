CXX=g++
LIB=../lib
SRC=../src
INC=../include


main: $(BIN)/net.o $(BIN)/model.o 
	$(CXX) -o $@ $(SRC)/main.c $(BIN)/net.o $(BIN)/model.o -I$(INC)

net.o: $(SRC)/net.c
	$(CXX) -o $net.o -c net.c
