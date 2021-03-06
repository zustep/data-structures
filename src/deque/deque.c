#include "deque.h"
#include <stdio.h>

deque *init_deque()
{
        deque *new_node = malloc(sizeof(deque));
        new_node->front = new_node->back = NULL;

        return new_node;
}

void int_front_display(deque *ptr)
{
        deque_node *node = ptr->front;

        do {
                printf("%d ", *(int*)node->data);
                node = node->next;
        } while (node != ptr->back->next);

        printf("\n");
}

void int_back_display(deque *ptr)
{
        deque_node *node = ptr->back;

        do {
                printf("%d ", *(int*)node->data);
                node = node->prev;
        } while (node != ptr->front->prev);

        printf("\n");
}

unsigned int deque_size(deque *ptr)
{
        unsigned int count = 0;
        deque_node *node = ptr->front;

        do {
                count++;
                node = node->next;
        } while (node != ptr->back->next);

        return count;
}

void free_deque(deque *ptr)
{
        deque_node *node = ptr->front;

        do {
                deque_node *temp = node;
                node = node->next;
                free(temp->data);
                free(temp);
        } while (node != ptr->back->next);
        
        free(ptr);
}

deque *pop_front(deque *ptr)
{
        deque_node *node = ptr->front;
        ptr->front = ptr->front->next;

        free(node->data);
        free(node);

        return ptr;
}

deque *pop_back(deque *ptr)
{
        deque_node *node = ptr->back;
        ptr->back = ptr->back->prev;

        free(node->data);
        free(node);

        return ptr;
}