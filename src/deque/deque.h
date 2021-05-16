#ifndef DEQUE_H
#define DEQUE_H

#include <stdlib.h>

typedef struct deque_node 
{
        void *data;
        struct deque_node *prev;
        struct deque_node *next;
}deque_node;

typedef struct deque
{
        deque_node *front;
        deque_node *back;
}deque;

deque *init_deque();
void int_front_display(deque *ptr); // test
void int_back_display(deque *ptr); // test
unsigned int deque_size(deque *ptr);
void free_deque(deque *ptr);
deque *pop_front(deque *ptr);
deque *pop_back(deque *ptr);

#define DEQUE_INSERT_FRONT_INIT(TYPE)                                   \
        deque* TYPE ##_insert_front(deque *ptr, TYPE value)             \
        {                                                               \
                deque_node *new_node = malloc(sizeof(deque_node));      \
                new_node->next = new_node->prev = NULL;                 \
                new_node->data = malloc(sizeof(TYPE));                  \
                *(TYPE*)new_node->data = value;                         \
                                                                        \
                if (ptr->front == NULL && ptr->back == NULL) {          \
                        ptr->front = ptr->back = new_node;              \
                        return ptr;                                     \
                }                                                       \
                                                                        \
                deque_node *temp = ptr->front;                          \
                ptr->front = new_node;                                  \
                new_node->prev = NULL;                                  \
                new_node->next = temp;                                  \
                temp->prev = new_node;                                  \
                                                                        \
                return ptr;                                             \
        }                                                               \

#define DEQUE_INSERT_BACK_INIT(TYPE)                                    \
        deque* TYPE ##_insert_back(deque *ptr, TYPE value)              \
        {                                                               \
                deque_node *new_node = malloc(sizeof(deque_node));      \
                new_node->next = new_node->prev = NULL;                 \
                new_node->data = malloc(sizeof(TYPE));                  \
                *(TYPE*)new_node->data = value;                         \
                                                                        \
                if (ptr->front == NULL && ptr->back == NULL) {          \
                        ptr->front = ptr->back = new_node;              \
                        return ptr;                                     \
                }                                                       \
                                                                        \
                deque_node *temp = ptr->back;                           \
                ptr->back = new_node;                                   \
                temp->next = new_node;                                  \
                new_node->prev = temp;                                  \
                new_node->next = NULL;                                  \
                                                                        \
                return ptr;                                             \
        }                                                               \

#define DEQUE_PEEK_FRONT_INIT(TYPE)                                     \
        TYPE TYPE ##_peek_front(deque *ptr)                             \
        {                                                               \
                if (ptr->front == NULL)                                 \
                        return NULL;                                    \
                return *(TYPE*)ptr->front->data;                        \
        }                                                               \

#define DEQUE_PEEK_BACK_INIT(TYPE)                                      \
        TYPE TYPE ##_peek_back(deque *ptr)                              \
        {                                                               \
                if (ptr->back == NULL)                                  \
                        return NULL;                                    \
                return *(TYPE*)ptr->back->data;                         \
        }                                                               \

#endif