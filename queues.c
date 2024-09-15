#include <stdio.h>
#include <stdlib.h>
struct queue{
    int size;
    int f;
    int r;
    int *arr;
};

int isempty(struct queue *q){
    if(q->f==q->r){
        return 1;
    }
    return 0;
}

int isfull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q,int val){
    if(isfull(q)){
        printf("Queue is full");
    }
    else{
        q->r=q->r+1;
        q->arr[q->r]=val;
    }
}

int dequeue(struct queue *q){
    int a=-1;
    if(isempty(q)){
        printf("no element to dequeue");
    }
    else{
        q->f=q->f+1;
        a=q->arr[q->f];
    }
    return a;
}

int main() {
    struct queue q;
    q.size=10;
    q.f=q.r=-1;
    q.arr=(int*)malloc(q.size*sizeof(int));//dynamic memory allocation of queue

    // if(isempty(&q)){
    //     printf("Queue is empty");
    // }
    // enqueue few elements
    enqueue(&q,12);
    enqueue(&q,15);
    enqueue(&q,20);
    enqueue(&q,17);
    printf("Dequeuing element %d\n",dequeue(&q));
    printf("Dequeuing element %d\n",dequeue(&q));

    return 0;
}