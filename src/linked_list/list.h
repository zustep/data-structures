#ifndef LIST_H
#define LIST_H

typedef struct node
{
	struct node *next;
	void *data;
}node, list;

/* linked list */
void list_int_display(node *head); //test
void list_float_display(node *head); // test
unsigned int list_size(node *head);
void free_list(node *head);

#define LIST_PUSH_FRONT_INIT(TYPE) 				\
	node* TYPE ##_push_front(node *head, TYPE value) 	\
	{ 							\
		node *new_node = malloc(sizeof(node)); 		\
		new_node->data = malloc(sizeof(TYPE)); 		\
		*(TYPE*)new_node->data = value; 		\
		new_node->next = head; 				\
		head = new_node;				\
		return head;					\
	} 							\

#define LIST_PUSH_BACK_INIT(TYPE) 				\
	node* TYPE ##_push_back(node *head, TYPE value)	 	\
	{ 							\
		node *new_node = malloc(sizeof(node));		\
		new_node->data = malloc(sizeof(TYPE)); 		\
		*(TYPE*)(new_node->data) = value; 		\
		new_node->next = NULL; 				\
								\
		if (head == NULL) 				\
			return new_node;			\
								\
		node *ptr = head;				\
		while (ptr->next != NULL) 			\
			ptr = ptr->next; 			\
		ptr->next = new_node; 				\
								\
		return head; 					\
	} 							\

#define LIST_ERASE_INIT(TYPE) 					\
	node* TYPE ##_erase(node *head, TYPE value) 		\
	{ 							\
		if (*(TYPE*)head->data == value) {		\
			node *ptr = head; 			\
			head = head->next; 			\
			free(ptr->data); 			\
			free(ptr); 				\
			return head; 				\
		} 						\
								\
		node *ptr = head, *prev; 			\
    		while (*(TYPE*)ptr->data != value) { 		\
        		prev = ptr; 				\
        		ptr = ptr->next; 			\
    		} 						\
    		prev->next = ptr->next; 			\
		free(ptr->data); 				\
    		free(ptr); 					\
								\
    		return head; 					\
	} 							\
/* linked list */

/* circular linked list */
void convert_to_circular(node *head);
void clist_int_display(node *head); //test
void clist_float_display(node *head); // test
unsigned int c_list_size(node *head);
void c_free_list(node *head);

#define CLIST_PUSH_FRONT_INIT(TYPE) 				\
	node* TYPE ##_c_push_front(node *head, TYPE value) 	\
	{ 							\
		node *new_node = malloc(sizeof(node)); 		\
		new_node->data = malloc(sizeof(TYPE)); 		\
    		*(TYPE*)new_node->data = value; 		\
    		new_node->next = head; 				\
								\
    		node *ptr = head; 				\
    		while (ptr->next != head) 			\
        		ptr = ptr->next; 			\
    		ptr->next = new_node; 				\
								\
    		return new_node; 				\
	} 							\

#define CLIST_PUSH_BACK_INIT(TYPE) 				\
	node* TYPE ##_c_push_back(node *head, TYPE value) 	\
	{ 							\
		node *new_node = malloc(sizeof(node)); 		\
		new_node->data = malloc(sizeof(TYPE)); 		\
    		*(TYPE*)new_node->data = value; 		\
		new_node->next = head; 				\
								\
		node *ptr = head; 				\
		while (ptr->next != head) 			\
			ptr = ptr->next; 			\
		ptr->next = new_node; 				\
								\
		return head; 					\
	} 							\

#define CLIST_ERASE_INIT(TYPE) 					\
	node* TYPE ##_c_erase(node *head, TYPE value) 		\
	{ 							\
		if (*(TYPE*)head->data == value) { 		\
			node *ptr = head; 			\
			while (ptr->next != head) 		\
				ptr = ptr->next; 		\
			ptr->next = head->next; 		\
			free(head->data); 			\
			free(head); 				\
			return ptr->next; 			\
		} 						\
								\
		node *ptr = head, *prev = NULL; 		\
		while (*(TYPE*)ptr->data != value) { 		\
			prev = ptr; 				\
			ptr = ptr->next; 			\
		} 						\
		prev->next = ptr->next; 			\
		ptr->next = prev; 				\
		free(ptr->data); 				\
		free(ptr); 					\
								\
		return head; 					\
	} 							\

/* circular linked list */

#endif
