#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

typedef struct queue_node
{
        struct queue_node *next;
        void *data;
}queue_node;

typedef struct queue
{
        queue_node *front;
        queue_node *rear;
}queue;

queue *init_queue();
void int_display(queue *q); //test
queue *pop(queue *q);
void free_queue(queue *q);
unsigned int queue_size(queue *q);

#define QUEUE_INSERT_INIT(TYPE)                                         \
        queue* TYPE ##_queue_insert(queue *q, TYPE value)               \
        {                                                               \
                queue_node *new_node = malloc(sizeof(queue_node));      \
                new_node->data = malloc(sizeof(TYPE));                  \
                *(TYPE*)new_node->data = value;                         \
                                                                        \
                if (q->front == NULL) {                                 \
                        q->front = new_node;                            \
                        q->rear = new_node;                             \
                        q->front->next = q->rear->next = NULL;          \
                        return q;                                       \
                }                                                       \
                                                                        \
                q->rear->next = new_node;                               \
                q->rear = new_node;                                     \
                q->rear->next = NULL;                                   \
                return q;                                               \
                                                                        \
        }                                                               \

#define QUEUE_PEEK_INIT(TYPE)                                           \
        TYPE TYPE ##_queue_peek(queue *q)                               \
        {                                                               \
                if (q->front == NULL)                                   \
                        return NULL;                                    \
                return *(TYPE*)q->front->data;                          \
        }                                                               \

#endif