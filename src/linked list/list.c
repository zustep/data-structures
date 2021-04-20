#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
	list *root_int = NULL, *root_float = NULL;

	PUSH_FRONT_INIT(int);
	PUSH_BACK_INIT(int);

	root_int = int_push_front(root_int, 1);
	root_int = int_push_front(root_int, 2);
	root_int = int_push_front(root_int, 3);
	int_display(root_int);

	convert_to_circular(root_int);
	C_PUSH_FRONT_INIT(int);
	C_PUSH_BACK_INIT(int);
	C_ERASE_INIT(int);
	root_int = int_c_push_front(root_int, 1337);
	root_int = int_c_push_front(root_int, 1555);
	root_int = int_c_push_back(root_int, 1488);
	c_int_display(root_int);
	root_int = int_c_erase(root_int, 1488);
	root_int = int_c_erase(root_int, 1);
	root_int = int_c_erase(root_int, 1337);
	root_int = int_c_erase(root_int, 2);
	root_int = int_c_erase(root_int, 3);
	root_int = int_c_erase(root_int, 1555);
	return 0;
}

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
    while (ptr)
    {
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
    do
    {
        printf("%d ", *(int*)ptr->data);
        ptr = ptr->next;
    } while (ptr != head);

    printf("\n");
}

void c_float_display(node *head)
{
	node *ptr = head;
    do
    {
        printf("%f ", *(float*)ptr->data);
        ptr = ptr->next;
    } while (ptr != head);

    printf("\n");
}

void c_free_list(node *head)
{
	node *ptr = head;
    do
    {
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
    do
    {
        count++;
        ptr = ptr->next;
    } while (ptr != head);
    
    return count;
}