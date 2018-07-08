StackClient: Stack_SeqList.o StackClient.o
	gcc -o StackClient StackClient.o Stack_SeqList.o

StackClient.o: Stack_SeqList.o StackClient.c
	gcc -c StackClient.c

Stack_SeqList.o: StackADT.h Stack_SeqList.c
	gcc -c Stack_SeqList.c
