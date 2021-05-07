#include <stdio.h>
#include "../acutest.h"
#include "../../src/queue/queue.h"

void test_insert()
{
        queue *q = init_queue();
        TEST_CHECK(q != NULL); 

        QUEUE_INSERT_INIT(int);
        q = int_queue_insert(q,1); 
        q = int_queue_insert(q,2);

        TEST_CHECK(*(int*)q->front->data == 1);
        TEST_CHECK(*(int*)q->rear->data == 2);
}

void test_pop()
{
        queue *q = init_queue();
        TEST_CHECK(q != NULL);
        QUEUE_INSERT_INIT(int);
        q = int_queue_insert(q,1); 
        q = int_queue_insert(q,2);

        q = pop(q);
        TEST_CHECK(*(int*)q->front->data == 2);
}

void test_peek()
{
        queue *q = init_queue();
        TEST_CHECK(q != NULL);
        QUEUE_INSERT_INIT(int);
        q = int_queue_insert(q,1);

        QUEUE_PEEK_INIT(int);

        TEST_CHECK(int_queue_peek(q) == 1);
}

void test_size()
{
        queue *q = init_queue();
        TEST_CHECK(q != NULL);
        QUEUE_INSERT_INIT(int);
        q = int_queue_insert(q,1);
        q = int_queue_insert(q,2);
        q = int_queue_insert(q,3);

        TEST_CHECK(queue_size(q) == 3);
}

TEST_LIST = {
        { "test_insert", test_insert },
        { "test_pop", test_pop },
        { "test_peek", test_peek },
        { "test_size", test_size },
        { NULL }
};
