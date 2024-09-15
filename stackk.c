#include <stdio.h>
#include <stdlib.h>
struct stack{
    int totalsize;
    int usedsize;
    int top;
    int *stk;
};

void setval(struct stack *s){
    s->top=-1;
    printf("Enter the totalsize of stack : ");
    scanf("%d",&s->totalsize);
    printf("No. of elements you want to store initally : ");
    scanf("%d",&s->usedsize);
    s->stk=(int*)malloc(s->totalsize*sizeof(int));
    for(int i=0;i<s->usedsize;i++){
        printf("enter element %d : ",i+1);
        scanf("%d",&s->stk[i]);
        s->top=s->top+1;
    }
}

void push(struct stack *s){
    if(s->top==s->totalsize){
        printf("stack is full");
    }
    else{
        int num;
        printf("Enter the element you want to push in stack : ");
        scanf("%d",&num);
        s->top=s->top+1;
        s->stk[s->top]=num;
    }
}

void pop(struct stack *s){
    if(s->top==-1){
        printf("Stack is empty\n");
    }
    else{
        printf("Popped element : %d\n",s->stk[s->top]);
        s->top=s->top-1;
    }
}

void display(struct stack *s){
    if(s->top>s->totalsize){
        printf("stack is full\n");
    }
    if(s->top==-1){
        printf("Stack is empty\n");
    }
    else{
        for(int i=s->top;i>=0;i--){
            printf("%d\t",s->stk[i]);
        }
        printf("\n");
    }
}

int choice;
void menu(){
    printf("\tMENU\n");
    printf("Enter 1 to push\nEnter 2 to pop\nEnter 3 to display\n4 Exit\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);
}

int main(){
    struct stack sk;
    setval(&sk);
    
    do{
        menu();
        switch (choice) {
            case 1:
            push(&sk);
            break;

            case 2:
            pop(&sk);
            break;

            case 3:
            display(&sk);
            break;

            case 4:
            printf("Exiting program");
            break;

            default:
            printf("invalid choice");
            break;
        }
    } while (choice!=4);
    
    free(sk.stk);   
}