#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void int_display(node *head)
{
	for (node *ptr = head; ptr; ptr = ptr->next)
		printf("%d ", *(int*)(ptr->data));
	printf("\n");
}

void float_display(node *head)
{
	for (node *ptr = head; ptr; ptr = ptr->next)
		printf("%f ", *(float*)(ptr->data));
	printf("\n");
}

unsigned int list_size(node *head)
{
	unsigned int count = 0;
	for (node *ptr = head; ptr; ptr = ptr->next)
		count++;
	return count;
}

void free_list(node *head)
{
	node *ptr = head;
	while (ptr != NULL) {
		node *temp = ptr;
        	ptr = ptr->next;
		free(temp->data);
        	free(temp);
	}
}

void convert_to_circular(node *head)
{
	node *ptr = head;
	while (ptr->next != NULL)
		ptr = ptr->next;

	ptr->next = head;
}

void c_int_display(node *head)
{
	node *ptr = head;
    	do {
        	printf("%d ", *(int*)ptr->data);
        	ptr = ptr->next;
	} while (ptr != head);

	printf("\n");
}

void c_float_display(node *head)
{
	node *ptr = head;
    	do {
        	printf("%f ", *(float*)ptr->data);
        	ptr = ptr->next;
	} while (ptr != head);

	printf("\n");
}

void c_free_list(node *head)
{
	node *ptr = head;
    	do {
        	node *temp = ptr;
        	ptr = ptr->next;
		free(temp->data);
        	free(temp);
	} while (ptr != head);
}

unsigned int c_list_size(node *head)
{
	unsigned int count = 0;
	node *ptr = head;
	do {
        	count++;
        	ptr = ptr->next;
	} while (ptr != head);

    	return count;
}
