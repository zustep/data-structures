CC = gcc

deque : deque.o deque_tests.o
	$(CC) -o deque deque.o deque_tests.o

deque.o : ../../src/deque/deque.h ../../src/deque/deque.c
	$(CC) -c ../../src/deque/deque.c

deque_tests.o : deque_tests.c ../acutest.h
	$(CC) -c deque_tests.c

clean:
	rm -rf *.o