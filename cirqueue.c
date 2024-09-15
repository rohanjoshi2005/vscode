#include <stdio.h>
#include <stdlib.h>
struct queue{
    int size;
    int f;
    int r;
    int* arr;
};


int isempty(struct queue *q){
    if(q->f==q->r){
        return 1;
    }
    return 0;
}

int isfull(struct queue *q){
    if((q->r+1)%q->size == q->f){
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q){
    if(isfull(q)){
        printf("Queue is full\n");
    }
    else{
        int val;
        printf("Enter the element you want to enqueue : ");
        scanf("%d",&val);
        q->r=(q->r+1)%q->size;
        q->arr[q->r]=val;
        
        printf("rear = %d\n",q->r);
        printf("front = %d\n",q->f);
    }
}

int dequeue(struct queue *q){
    int a=-1;
    if(isempty(q)){
        printf("no element to dequeue\n");
    }
    else{
        q->f=(q->f+1)%q->size;
        a=q->arr[q->f];
        printf("Dequeuing element %d\n",a);

        printf("rear = %d\n",q->r);
        printf("front = %d\n",q->f);
    }
    return a;
}

void display(struct queue *q){
    if(isempty(q)){
        printf("No elements to display\n");
    }
    else{
        for(int i=q->f;i<=q->r;i++){
            printf("%d\t",q->arr[i]);
        }
        printf("\n");
    }
}

int choice=-1;
void menu(){
    printf("\tMENU\n");
    printf("Enter 1 to enque\nEnter 2 to dequeue\nEnter 3 to show\nEnter 4 to exit\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);
}

int main() {
    struct queue q;
    printf("Enter the size of queue : ");
    scanf("%d",&q.size);
    q.f=q.r=0;
    q.arr=(int*)malloc(q.size*sizeof(int));//dynamic memory allocation of queue
    
    do{
        menu();
        switch (choice) {
            case 1:
                enqueue(&q);
                break;

            case 2:
                dequeue(&q);
                break;

            case 3:
                display(&q);
                break;

            case 4:
                printf("Exiting the program");
                break;

            default:
                printf("invalid choice\n");
                break;
        }      
    }while(choice!=4);  
    
    
    return 0;
}
    // if(isempty(&q)){
    //     printf("Queue is empty\n");
    // }

    // if(isfull(&q)){
    //     printf("Queue is full\n");
    // }



