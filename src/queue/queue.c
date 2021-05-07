#include "queue.h"
#include <stdio.h>

/*int main(int argc, char *argv[])
{
        queue *q = init_queue();    
        QUEUE_INSERT_INIT(int);
        QUEUE_PEEK_INIT(int);
        q = int_queue_insert(q,4); 
        q = int_queue_insert(q,3);
        q = int_queue_insert(q,2);                    
        int_display(q);
        printf("size = %d\n", queue_size(q));
        printf("front = %d\n", int_queue_peek(q));
        q = pop(q);
        int_display(q);
        free_queue(q);
        return 0;
}*/


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
