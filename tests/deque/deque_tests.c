#include <stdio.h>
#include "../acutest.h"
#include "../../src/deque/deque.h"

void test_push_front()
{
        deque *d = init_deque();
        TEST_CHECK(d != NULL);

        DEQUE_INSERT_FRONT_INIT(int);
        d = int_insert_front(d,1);
        d = int_insert_front(d,2);
        d = int_insert_front(d,3);

        TEST_CHECK(*(int*)d->front->data == 3);
        TEST_CHECK(*(int*)d->front->next->data == 2);
        TEST_CHECK(*(int*)d->back->prev->data == 2);
        TEST_CHECK(*(int*)d->back->data == 1);

        free_deque(d);
}

void test_push_back()
{
        deque *d = init_deque();
        TEST_CHECK(d != NULL);

        DEQUE_INSERT_BACK_INIT(int);
        d = int_insert_back(d,1);
        d = int_insert_back(d,2);
        d = int_insert_back(d,3);

        TEST_CHECK(*(int*)d->back->data == 3);
        TEST_CHECK(*(int*)d->front->next->data == 2);
        TEST_CHECK(*(int*)d->back->prev->data == 2);
        TEST_CHECK(*(int*)d->front->data == 1);

        free_deque(d);
}

void test_pop()
{
        deque *d = init_deque();
        TEST_CHECK(d != NULL); 

        DEQUE_INSERT_FRONT_INIT(int);
        d = int_insert_front(d,1);
        d = int_insert_front(d,2);
        d = int_insert_front(d,3);
        d = int_insert_front(d,4);
        d = int_insert_front(d,5);

        d = pop_back(d);
        d = pop_front(d);

        TEST_CHECK(*(int*)d->front->data == 4);
        TEST_CHECK(*(int*)d->back->data == 2);

        free_deque(d);
}

void test_peek()
{
        deque *d = init_deque();
        TEST_CHECK(d != NULL); 

        DEQUE_INSERT_BACK_INIT(int);
        DEQUE_PEEK_FRONT_INIT(int);
        DEQUE_PEEK_BACK_INIT(int);
        d = int_insert_back(d,1);
        d = int_insert_back(d,2);
        d = int_insert_back(d,3);

        TEST_CHECK(int_peek_front(d) == 1);
        TEST_CHECK(int_peek_back(d) == 3);

        free_deque(d);
}

void test_size()
{
        deque *d = init_deque();
        TEST_CHECK(d != NULL); 

        DEQUE_INSERT_BACK_INIT(int);
        DEQUE_INSERT_FRONT_INIT(int);
        d = int_insert_back(d,1);
        d = int_insert_back(d,2);
        d = int_insert_back(d,3);
        d = int_insert_front(d,4);
        d = int_insert_front(d,5);

        TEST_CHECK(deque_size(d) == 5);
        d = pop_back(d);
        TEST_CHECK(deque_size(d) == 4);
        d = pop_front(d);
        TEST_CHECK(deque_size(d) == 3);

        free_deque(d);
}

TEST_LIST = {
        { "test_push_front", test_push_front },
        { "test_push_back", test_push_back },
        { "test_pop", test_pop },
        { "test_peek", test_peek },
        { "test_size", test_size },
        { NULL }
};
