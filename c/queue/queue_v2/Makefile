main: main.o queue.o
	gcc -o main main.o queue.o

main.o: queue.o main.c
	gcc -c -g main.c

queue.o: queue.h err.h queue.c
	gcc -c -g queue.c

clean: queue.o main.o
	rm *.o
