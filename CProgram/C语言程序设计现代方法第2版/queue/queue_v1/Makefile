Demo: Queue.o Demo.o
	gcc -g -o Demo Queue.o Demo.o

Demo.o: Queue.o Demo.c
	gcc -c Demo.c

Queue.o: QueueADT.h ErrorDeal.h Queue.c
	gcc -c Queue.c

clean:
	rm *.o
