#include <stdio.h>
#include "queue.h"

void CreateQueue(Queue *q)
{
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

boolean isEmpty(Queue q)
{
    return IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF;
}

boolean isFull(Queue q)
{
    return IDX_HEAD(q) == (IDX_TAIL(q) + 1) % CAPACITY;
}

int length(Queue q)
{
    if (isEmpty(q))
    {
        return 0;
    }
    else
    {
        return (IDX_TAIL(q) - IDX_HEAD(q) + CAPACITY) % CAPACITY + 1;
    }
}

void enqueue(Queue *q, ElType val)
{
    if (isFull(*q))
    {
        printf("Queue is full!\n");
    }
    else
    {
        if (isEmpty(*q))
        {
            IDX_HEAD(*q) = 0;
            IDX_TAIL(*q) = 0;
            HEAD(*q) = val;
        }else{
        IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % CAPACITY;
        TAIL(*q) = val;}
    }
}

void dequeue(Queue *q, ElType *val)
{
    if (isEmpty(*q))
    {
        printf("Queue is empty!\n");
    }
    else
    {
        *val = HEAD(*q);
        if (IDX_HEAD(*q) == IDX_TAIL(*q))
        {
            IDX_HEAD(*q) = IDX_UNDEF;
            IDX_TAIL(*q) = IDX_UNDEF;
        }
        else
        {
            IDX_HEAD(*q) = (IDX_HEAD(*q) + 1) % CAPACITY;
        }
    }
}


void displayQueue(Queue q)
{
    if (isEmpty(q))
    {
        printf("[]\n");
    }
    else
    {
        int i;
        printf("[");
        for (i = IDX_HEAD(q); i != IDX_TAIL(q); i = (i + 1) % CAPACITY)
        {
            printf("%d,", q.buffer[i]);
        }
        printf("%d]\n", TAIL(q));
    }
}

void dequeueAt(Queue *q, int idx, ElType *val){
    if (isEmpty(*q))
    {
        printf("Queue is empty!\n");
    } else if(idx == 0){
                dequeue(q, val);
    }else{
        *val = q->buffer[idx];
        for (int i = IDX_HEAD(*q)+idx; i != IDX_TAIL(*q); i = (i + 1) % CAPACITY){  
            q->buffer[i] = q->buffer[(i + 1) % CAPACITY];
        }
    }
    IDX_TAIL(*q) = (IDX_TAIL(*q) - 1) % CAPACITY;  
}
