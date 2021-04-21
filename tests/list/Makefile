CC = gcc

list : list_tests.o list.o
	$(CC) -o list list_tests.o list.o

list_tests.o : list_tests.c ../acutest.h
	$(CC) -c list_tests.c

list.o : ../../src/linked_list/list.c ../../src/linked_list/list.h
	$(CC) -c ../../src/linked_list/list.c

clean:
	rm -f *.o
