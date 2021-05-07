CC = gcc

queue : queue_tests.o queue.o
	$(CC) -o queue queue.o queue_tests.o

queue_tests.o : queue_tests.c ../acutest.h
	$(CC) -c queue_tests.c

queue.o : ../../src/queue/queue.c ../../src/queue/queue.h
	$(CC) -c ../../src/queue/queue.c

clean :
	rm -rf *.o