#ifndef DLIST_H
#define DLIST_H
#include <stdlib.h>

typedef struct dlist
{
	void *data;
	struct dlist *next;
	struct dlist *prev;
}dlist;

/* doubly linked list */

void dlist_int_display(dlist *head);
unsigned int dlist_size(dlist *head);
void free_dlist(dlist *head);
void dlist_float_displyat(dlist *head);

#define DLIST_PUSH_FRONT_INIT(TYPE)				\
	dlist* TYPE ##_push_front(dlist *head, TYPE value)	\
	{							\
		dlist *new_node = malloc(sizeof(dlist));	\
		new_node->data = malloc(sizeof(TYPE));		\
		*(TYPE*)new_node->data = value;			\
								\
		if (head == NULL) {				\
			new_node->prev = NULL;			\
			new_node->next = NULL;			\
			return new_node;			\
		}						\
								\
		new_node->prev = NULL;				\
		new_node->next = head;				\
		head->prev = new_node;				\
		return new_node;				\
	}							\

#define DLIST_PUSH_BACK_INIT(TYPE)				\
	dlist* TYPE ##_push_back(dlist *head, TYPE value) 	\
	{							\
		dlist *new_node = malloc(sizeof(dlist));        \
                new_node->data = malloc(sizeof(TYPE));          \
                *(TYPE*)new_node->data = value;                 \
                                                                \
                if (head == NULL) {                             \
                        new_node->prev = NULL;                  \
                        new_node->next = NULL;                  \
                        return new_node;                        \
                }						\
								\
		dlist *ptr = head;				\
		while (ptr->next != NULL)			\
			ptr = ptr->next;			\
								\
		ptr->next = new_node;				\
		new_node->prev = ptr;				\
		new_node->next = NULL;				\
								\
		return head;					\
	}							\

#define DLIST_ERASE_INIT(TYPE)					\
	dlist* TYPE ##_erase(dlist *head, TYPE value)		\
	{							\
		if (*(TYPE*)head->data == value) { 		\
			dlist *ptr = head;			\
			head = head->next;			\
			head->prev = NULL;			\
			free(ptr->data);			\
			free(ptr);                              \
                        return head;				\
		}						\
								\
		dlist *ptr = head, *prev = NULL;		\
		while (*(TYPE*)ptr->data != value) {		\
			prev = ptr;				\
			ptr = ptr->next;			\
		}						\
								\
		if (ptr->next == NULL) {			\
			ptr->prev->next = NULL;			\
			free(ptr->data);			\
			free(ptr);				\
			return head;				\
		}						\
		prev->next = ptr->next;				\
		ptr->next->prev = prev;				\
		free(ptr->data);				\
		free(ptr);					\
		return head;					\
	}							\
/* doubly linked list */


#endif
