#include "queue.h"
#include <stdio.h>

queue *init_queue()
{
        queue *q = malloc(sizeof(queue));
        q->front = q->rear = NULL;
        return q;
}

queue *pop(queue *q)
{
        queue_node *ptr = q->front;
        q->front = q->front->next;
        free(ptr->data);
        free(ptr);
        return q;
}

unsigned int queue_size(queue *q)
{
        queue_node *ptr = q->front;
        unsigned int count = 0;

        do {
                count++;
                ptr = ptr->next;
        } while(ptr != q->rear->next);

        return count;
}

void free_queue(queue *q)
{
        queue_node *ptr = q->front;

        do {
                queue_node *tmp = ptr;
                ptr = ptr->next;
                free(tmp->data);
                free(tmp);
        } while(ptr != NULL);

        free(q);
}

void int_display(queue *q)
{
    queue_node *ptr = q->front;

    do {
                printf("%d ", *(int*)ptr->data);
                ptr = ptr->next;
    } while (ptr != q->rear->next);

    printf("\n");
}
