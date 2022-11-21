#include"queue.c"
#include<stdio.h>
int main(){
    Queue q;
    char* a;
    CreateQueue(&q);
    if(isEmpty(q)){
        a="a";
        enqueue(&q,a);
        printf("panjang = %d\n",length(q));
        dequeue(&q,&a);
        printf("panjang = %d\n",length(q));
        while(!isFull(q)){
            enqueue(&q,"c");
            enqueue(&q,"r");
        }
        printf("panjang = %d\n",length(q));

    }else{
        printf("Queue tidak kosong\n");
    }

    return 0;
}