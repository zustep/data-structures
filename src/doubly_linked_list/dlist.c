#include <stdio.h>
#include "dlist.h"

int main(int argc, char *argv[])
{
	dlist *root = NULL;
	DLIST_PUSH_FRONT_INIT(int);
	DLIST_PUSH_BACK_INIT(int);
	DLIST_ERASE_INIT(int);
	root = int_push_front(root, 1);
	root = int_push_front(root, 2);
	root = int_push_front(root, 3);
	root = int_push_back(root, 1337);
        printf("size = %d\n", dlist_size(root));
	root = int_erase(root, 1337);
	root = int_erase(root, 3);
	root = int_erase(root, 2);
        printf("size = %d\n", dlist_size(root));
	dlist_int_display(root);
        free_dlist(root);


	return 0;
}

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
