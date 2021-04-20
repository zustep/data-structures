#ifndef LIST_H
#define LIST_H

typedef struct node
{
	struct node *next;
	void *data;
}node;

#define PUSH_FRONT_INIT(TYPE) \
	node* TYPE ##_push_front(node *head, TYPE value) \
	{ \
		node *new_node = malloc(sizeof(node)); \
		new_node->data = malloc(sizeof(value)); \
		*(TYPE*)(new_node->data) = value; \
		new_node->next = head; \
		return new_node; \
	} \

#define PUSH_BACK_INIT(TYPE) \
	node* TYPE ##_push_back(node *head, TYPE value) \
	{ \
		node *new_node = malloc(sizeof(node)); \
		new_node->data = malloc(sizeof(value)); \
		*(TYPE*)(new_node->data) = value; \
		new_node->next = NULL; \
		\
		if (head == NULL) return new_node; \
		\
		node *ptr = head;\
		while (ptr->next != NULL) \
			ptr = ptr->next; \
		ptr->next = new_node; \
		\
		return head; \
	} \

unsigned int list_size(node *head);
void int_display(node *head);
void float_display(node *head);

#endif
