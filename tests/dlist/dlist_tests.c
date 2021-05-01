#include <stdio.h>
#include "../acutest.h"
#include "../../src/doubly_linked_list/dlist.h"

void test_push()
{
        dlist *l = NULL;
        DLIST_PUSH_FRONT_INIT(int);
        DLIST_PUSH_BACK_INIT(int);
    
        l = int_push_front(l , 1);
        TEST_CHECK(l != NULL);
        TEST_CHECK(*(int*)l->data == 1);
    
        l = int_push_back(l, 2);
        TEST_CHECK(l != NULL);
        TEST_CHECK(*(int*)l->next->data == 2);
    
        free_dlist(l);
}

void test_free()
{
        DLIST_ERASE_INIT(int);
        DLIST_PUSH_FRONT_INIT(int);
    
        dlist *l = NULL;
        l = int_push_front(l , 1);
        l = int_push_front(l , 2);
        l = int_push_front(l , 3); 
        // 3->2->1
        l = int_erase(l, 1); // 3->2
        TEST_CHECK(*(int*)l->data == 3);
        TEST_CHECK(*(int*)l->next->data == 2);
        l = int_erase(l, 3); // 2
        TEST_CHECK(*(int*)l->data == 2);
    
        free_dlist(l);
}

void test_size()
{
        dlist *l = NULL;
        DLIST_PUSH_FRONT_INIT(int);

        l = int_push_front(l, 1);
        l = int_push_front(l, 2);
        l = int_push_front(l, 3);

        TEST_CHECK(dlist_size(l) == 3);
    
        free_dlist(l);
}

void c_test_push()
{
        dlist *l = NULL;

        DLIST_PUSH_FRONT_INIT(int);
        CDLIST_PUSH_FRONT_INIT(int);
        DLIST_PUSH_BACK_INIT(int);

        l = int_push_front(l , 1337);
        TEST_CHECK(l != NULL);
        l = int_push_front(l , 31337);
        TEST_CHECK(l != NULL);

        convert_to_circular(l);

        l = int_c_push_front(l , 1);
        TEST_CHECK(l != NULL);
        l = int_c_push_front(l , 2);
        TEST_CHECK(l != NULL);
        l = int_c_push_front(l , 3);
        TEST_CHECK(l != NULL); 

        TEST_CHECK(*(int*)l->data == 3);

        c_free_dlist(l);
}

void c_test_free()
{
        dlist *l = NULL;

        CDLIST_ERASE_INIT(int);
        CDLIST_PUSH_FRONT_INIT(int);
        DLIST_PUSH_FRONT_INIT(int);
    
        l = int_push_front(l , 1337);
        TEST_CHECK(l != NULL); 
        l = int_push_front(l , 31337);
        TEST_CHECK(l != NULL); 
    
        convert_to_circular(l);
    
        l = int_c_push_front(l , 1);
        TEST_CHECK(l != NULL); 
        l = int_c_push_front(l , 2);
        TEST_CHECK(l != NULL); 
        l = int_c_push_front(l , 3);
        TEST_CHECK(l != NULL);  
   
        // (root)3->2->1->31337->1337->root

        l = int_c_erase(l, 3); // (root)2->1->31337->1337->root
        TEST_CHECK(*(int*)l->data == 2);
    
        l = int_c_erase(l, 31337); // (root)2->1->1337->root
        TEST_CHECK(*(int*)l->next->next->data == 1337);

        c_free_dlist(l);
}

void c_test_size()
{
        dlist *l = NULL;
        DLIST_PUSH_FRONT_INIT(int);
        CDLIST_PUSH_FRONT_INIT(int);

        l = int_push_front(l , 1337);
        TEST_CHECK(l != NULL); 
        l = int_push_front(l , 31337);
        TEST_CHECK(l != NULL); 

        convert_to_circular(l);

        l = int_c_push_front(l, 1);
        l = int_c_push_front(l, 2);
        l = int_c_push_front(l, 3);
    
        TEST_CHECK(c_dlist_size(l) == 5);
    
        c_free_dlist(l);
}

TEST_LIST = {
        { "test_push", test_push },
        { "test_free", test_free },
        { "test_size", test_size },
        { "c_test_push", c_test_push },
        { "c_test_free", c_test_free },
        { "c_test_size", c_test_size },
        { NULL }
};