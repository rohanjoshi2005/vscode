// #include <stdio.h>
// int main() {
//     int arr[10], i;
//     for (i = 0; i < 10; i++)
//     {
//         printf("Enter the value for index %d\n: ",i);
//         scanf("%d",&arr[i]);
//     }
//     for (i = 0; i < 10; i++)
//     {
//         printf("The value for index %d is %d\n",i,arr[i]);
//     }
    
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
struct myarray{
    int totalsize;
    int usedsize;
    int *arr;
};

void createarray(struct myarray *a){
    printf("Enter the total size of array : ");
    scanf("%d",&a->totalsize);
    printf("Enter the size you want to use : ");
    scanf("%d",&a->usedsize);
    a->arr=(int*)malloc((a->totalsize)*sizeof(int));
}

void setval(struct myarray *a){
    for(int i=0;i<a->usedsize;i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",&((a->arr)[i]));
    }
}


void del(struct myarray *a){
    int index;
    printf("Enter the index which you want to delete : ");
    scanf("%d",&index);
    if(index>=a->usedsize || index<0){
        printf("deletion is not possible\n");
        return;
    } else {
        for(int i=index;i<(a->usedsize-1);i++){
            a->arr[i]=a->arr[i+1];
        }
        a->usedsize--;
    }
}

void add(struct myarray *a){
    int num,index;
    if(a->usedsize>=a->totalsize){
        printf("Array is full");
        return;
    } 
    printf("Enter the index at which you want to add : ");
    scanf("%d",&index);
    if (index < 0 || index > a->usedsize) {
        printf("Invalid index\n");
        return;
    }
    printf("Enter the element which you want to add : ");
    scanf("%d",&num);
    for(int i=a->usedsize-1;i>=index;i--){
        a->arr[i]=a->arr[i-1];
    }
    a->usedsize++;
    a->arr[index]=num;
}


void display(struct myarray *a){
    if(a->usedsize==0){
        printf("Array is empty");
    } else{
        for(int i=0;i<a->usedsize;i++){
        printf("%d\t",a->arr[i]);
        }
        printf("\n");
    }    
}

int choice;
void menu(){
    printf("\tMENU\n");
    printf("Enter 1 to add element\nEnter 2 to delete element\nEnter 3 to display\nEnter 4 to exit\n");
    printf("Enter your choice :");
    scanf("%d",&choice);
}

int main(){
    struct myarray marks;
    createarray(&marks);
    setval(&marks);
    do{
        menu();
        switch (choice)
        {
            case 1:
            add(&marks);
            break;

            case 2:
            del(&marks);
            break;

            case 3:
            display(&marks);
            break;

            case 4:
            printf("Exiting the program");
            break;

            default:
            printf("Invalid choice");
            break;
        }
    }while(choice!=4);

    free(marks.arr);
}