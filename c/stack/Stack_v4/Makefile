StackClient: Stack.o StackClient.o
	gcc -o StackClient Stack.o StackClient.o

StackClient.o: StackClient.c Stack.o
	gcc -c StackClient.c

Stack.o: Stack.c StackADT.h
	gcc -c Stack.c
