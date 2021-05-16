#include "deque.h"
#include <stdio.h>

int main()
{
        DEQUE_INSERT_FRONT_INIT(int);
        DEQUE_INSERT_BACK_INIT(int);
        deque *d = init_deque();

        d = int_insert_front(d,1);
        d = int_insert_front(d,2);
        d = int_insert_front(d,3);

        d = int_insert_back(d,4);
        d = int_insert_back(d,5);
        d = int_insert_back(d,6);

        int_front_display(d);
        int_back_display(d);

        printf("size = %d\n", deque_size(d));

}

deque *init_deque()
{
        deque *new_node = malloc(sizeof(deque));
        new_node->front = new_node->back = NULL;

        return new_node;
}

void int_front_display(deque *ptr)
{
        for (deque_node *node = ptr->front; node; node = node->next)
                printf("%d ", *(int*)node->data);
        printf("\n");
}

void int_back_display(deque *ptr)
{
        for (deque_node *node = ptr->back; node; node = node->prev)
                printf("%d ", *(int*)node->data);
        printf("\n");
}

unsigned int deque_size(deque *ptr)
{
        unsigned int count = 0;
        for (deque_node *node = ptr->front; node; node = node->next)
                count++;
        return count;
}