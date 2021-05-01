#ifndef STACK_H
#define STACK_H
#include <stdlib.h>

typedef struct node
{
        void *data;
        struct node *next;
}node,stack;

node *pop(node *top);
void int_display(node *top); //test
void free_stack(node *top);
unsigned int stack_size(node *top);

#define STACK_PUSH_INIT(TYPE)                                   \
        node* TYPE ##_stack_push(node *top, TYPE value)         \
        {                                                       \
                node *new_node = malloc(sizeof(node));          \
                new_node->data = malloc(sizeof(TYPE));          \
                *(TYPE*)new_node->data = value;                 \
                                                                \
                if (top == NULL) {                              \
                        new_node->next = NULL;                  \
                        return new_node;                        \
                }                                               \
                                                                \
                new_node->next = top;                           \
                return new_node;                                \
        }                                                       \

#define STACK_PEEK_INIT(TYPE)                                   \
        TYPE TYPE ##_stack_peek(node *top)                      \
        {                                                       \
                if (top == NULL)                                \
                        return NULL;                            \
                return *(TYPE*)top->data;                       \
        }                                                       \

#endif