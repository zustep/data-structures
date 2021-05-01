#include <stdio.h>
#include "dlist.h"

void dlist_int_display(dlist *head)
{
	for (dlist *ptr = head; ptr; ptr = ptr->next)
		printf("%d ", *(int*)ptr->data);
	printf("\n");
}

void dlist_float_display(dlist *head)
{
	for (dlist *ptr = head; ptr; ptr = ptr->next)
		printf("%f ", *(float*)ptr->data);
	printf("\n");
}

void free_dlist(dlist *head)
{
        dlist *ptr = head;
        while (ptr != NULL) {
                dlist *tmp = ptr;
                ptr = ptr->next;
                free(tmp->data);
                free(tmp);
        }
}

unsigned int dlist_size(dlist *head)
{       
       unsigned int count = 0;
        for (dlist *ptr = head; ptr; ptr = ptr->next)
                count++;
        return count;
}

void convert_to_circular(dlist *head)
{
        dlist *ptr = head;
        while (ptr->next != NULL) {
                ptr = ptr->next;
        }

        head->prev = ptr;
        ptr->next = head;
}

void c_int_display(dlist *head)
{
        dlist *ptr = head;
        do {
                printf("%d ", *(int*)ptr->data);
                ptr = ptr->next;
        } while (ptr != head);
    
    printf("\n");
}

void c_free_dlist(dlist *head)
{
        dlist *ptr = head;
        do {
                dlist *tmp = ptr;
                ptr = ptr->next;
                free(tmp->data);
                free(tmp);
        } while(ptr != head);
}

unsigned int c_dlist_size(dlist *head)
{
        dlist *ptr = head;
        unsigned int count = 0;
        do {
                count++;
                ptr = ptr->next;
        } while(ptr != head);

    return count;
}