#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
	node *root_int = NULL, *root_float = NULL;

	PUSH_FRONT_INIT(int);
	PUSH_BACK_INIT(int);

	root_int = int_push_front(root_int, 1);
	root_int = int_push_front(root_int, 2);
	root_int = int_push_front(root_int, 3);

	root_int = int_push_back(root_int, 3);
	root_int = int_push_back(root_int, 2);
	root_int = int_push_back(root_int, 1);

	int_display(root_int);

	PUSH_FRONT_INIT(float);
	PUSH_BACK_INIT(float);

	root_float = float_push_front(root_float, 1.1f);
	root_float = float_push_front(root_float, 2.2f);
	root_float = float_push_front(root_float, 3.3f);

	root_float = float_push_back(root_float, 3.3f);
	root_float = float_push_back(root_float, 2.2f);
	root_float = float_push_back(root_float, 1.1f);

	float_display(root_float);

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