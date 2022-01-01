all:main
all:driver

main: AbstractHex.o hw5main.o HexArray1D.o  HexVector.o
	g++ AbstractHex.o hw5main.o HexArray1D.o  HexVector.o -o main

driver: AbstractHex.o driver.o HexArray1D.o  HexVector.o
	g++ AbstractHex.o driver.o HexArray1D.o  HexVector.o -o driver
		
		
AbstractHex.o: AbstractHex.cpp
	g++ -c -std=c++11 AbstractHex.cpp
	
hw5main.o: hw5main.cpp
	g++ -c -std=c++11 hw5main.cpp

driver.o: driver.cpp
	g++ -c -std=c++11 driver.cpp


HexArray1D.o: HexArray1D.cpp	
	g++ -c -std=c++11 HexArray1D.cpp



HexVector.o: HexVector.cpp
	g++ -c -std=c++11 HexVector.cpp	
	
clear: 
	rm *.o main		
