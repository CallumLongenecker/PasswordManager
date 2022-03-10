# makefile for Time class with three files:
# Time.h, Time.cpp, Driver.cpp
# Try "-std=gnu++0x" or "-std=c++11"

a.out: PasswordDriver.o PasswordManager.o
	g++ PasswordDriver.o PasswordManager.o

PasswordDriver.o: PasswordDriver.cpp PasswordManager.h
	g++ -c -std=gnu++0x PasswordDriver.cpp

PasswordManager.o: PasswordManager.cpp PasswordManager.h
	g++ -c -std=gnu++0x PasswordManager.cpp



