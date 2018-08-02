StackClient: Stack.o StackClient.o
	gcc -o StackClient Stack.o StackClient.o

StackClient.o: Stack.o StackClient.c
	gcc -c StackClient.c

Stack.o: StackADT.h Stack.c
	gcc -c Stack.c
