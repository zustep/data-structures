CC = gcc

stack : stack_tests.o stack.o
	$(CC) -o stack stack.o stack_tests.o

stack_tests.o : stack_tests.c ../acutest.h
	$(CC) -c stack_tests.c

stack.o : ../../src/stack/stack.c ../../src/stack/stack.h
	$(CC) -c ../../src/stack/stack.c

clean :
	rm -rf *.o