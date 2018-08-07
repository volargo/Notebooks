getopt_long: main.o getopt_long.o err.o
	gcc $(CFLAGS) main.o getopt_long.o err.o -o getopt_long

main.o: main.c getopt_long.c err.c getopt_long.h
	gcc -c main.c

getopt_long.o: err.c getopt_long.c getopt_long.h
	gcc -c getopt_long.c

err.o: getopt_long.h
	gcc -c err.c

clean:
	rm -rf *.o getopt_long
