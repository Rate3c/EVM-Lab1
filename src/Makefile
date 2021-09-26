CC=g++
CFLAG=-c -Wall

all: output clean

output: EVMLab1.o BitSwapper.o IOUtility.o UserInterface.o
	$(CC) EVMLab1.o BitSwapper.o IOUtility.o UserInterface.o -o output

EVMLab1.o: EVMLab1.cpp
	$(CC) $(CFLAG) EVMLab1.cpp

BitSwapper.o: BitSwapper.cpp BitSwapper.h
	$(CC) $(CFLAG) BitSwapper.cpp

IOUtility.o: IOUtility.cpp IOUtility.h
	$(CC) $(CFLAG) IOUtility.cpp

UserInterface.o: UserInterface.cpp UserInterface.h
	$(CC) $(CFLAG) UserInterface.cpp

clean:
	@echo "Cleaning up..."
	rm *.o