#include "stack.h"
#include <stdio.h>

node *pop(node *top)
{
        node *ptr = top;
        top = top->next;
        free(ptr->data);
        free(ptr);
        
        return top;
}

void free_stack(node *top)
{
        node *ptr = top;
        while (ptr != NULL) {
                node *tmp = ptr;
                ptr = ptr->next;
                free(tmp->data);
                free(tmp);
        }
}

unsigned int stack_size(node *top)
{
        unsigned int count = 0;
	for (node *ptr = top; ptr; ptr = ptr->next)
		count++;
	return count;
}

void int_display(node *top)
{
        node *ptr = top;
        while (ptr != NULL) {
                printf("%d ", *(int*)ptr->data);
                ptr = ptr->next;
        }
        printf("\n");
}