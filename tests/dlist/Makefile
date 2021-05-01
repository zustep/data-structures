CC = gcc

dlist : dlist_tests.o dlist.o
	$(CC) -o dlist dlist_tests.o dlist.o

dlist_tests.o : dlist_tests.c ../acutest.h
	$(CC) -c dlist_tests.c

dlist.o : ../../src/doubly_linked_list/dlist.c ../../src/doubly_linked_list/dlist.h
	$(CC) -c ../../src/doubly_linked_list/dlist.c

clean:
	rm -f *.o