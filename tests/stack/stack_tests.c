#include <stdio.h>
#include "../acutest.h"
#include "../../src/stack/stack.h"

void test_push()
{
        stack *top = NULL;
        STACK_PUSH_INIT(int);
        top = int_stack_push(top, 1);
        TEST_CHECK(*(int*)top->data == 1);
        top = int_stack_push(top, 2);
        TEST_CHECK(*(int*)top->data == 2);

        free_stack(top);
}

void test_pop()
{
        stack *top = NULL;
        STACK_PUSH_INIT(int);
        top = int_stack_push(top, 1);
        top = int_stack_push(top, 2);

        top = pop(top);
        TEST_CHECK(*(int*)top->data == 1);

        free_stack(top);
}

void test_peek()
{
        stack *top = NULL;
        STACK_PUSH_INIT(int);
        STACK_PEEK_INIT(int);
        top = int_stack_push(top, 1);

        TEST_CHECK(int_stack_peek(top) == 1);
        
        free_stack(top);
}

void test_size()
{
        stack *top = NULL;
        STACK_PUSH_INIT(int);
        top = int_stack_push(top, 1);
        top = int_stack_push(top, 2);
        top = int_stack_push(top, 3);
        top = int_stack_push(top, 4);

        TEST_CHECK(stack_size(top) == 4);

        free_stack(top);
}

TEST_LIST = {
        { "test_push", test_push },
        { "test_pop", test_pop },
        { "test_peek", test_peek },
        { "test_size", test_size },
        { NULL }
};
