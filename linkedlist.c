#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *link;
};

int main() {
    struct node *head = NULL, *newnode, *ptr, *del;
    int num, value;
    printf("No. of elements you want to store in a linked list : ");
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter element %d : ", i + 1);
        scanf("%d", &value);
        newnode->data = value;
        newnode->link = NULL;

        if (head == NULL) {
            head = newnode;
        }
        else {
            ptr->link = newnode;
        }
        ptr = newnode;
    }


    int choice,first,last,index,val;
    do {
        printf("\n*****MENU*****\n");
        printf("Enter 1 to insert at index\nEnter 2 to delete at index\nEnter 3 to display linked list\nEnter 4 to exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
            
            // case 1:
            // printf("Enter the number you want to insert : ");
            // scanf("%d", &first);
            // newnode = (struct node *)malloc(sizeof(struct node));
            // newnode->data = first;
            // newnode->link = head;
            // head = newnode;
            // // ptr = head;
            // break;

            case 1:
            printf("Enter the index where you want to insert : ");
            scanf("%d",&index);
            if(index==0){
                newnode=(struct node *)malloc(sizeof(struct node));
                printf("Enter the number you want to insert : ");
                scanf("%d", &val);
                newnode->data=val;
                newnode->link=head;
                head=newnode;
            }
            else if(index<0 || index>num){
                printf("INVALID INDEX");
            } 
            else {
                newnode=(struct node *)malloc(sizeof(struct node));
                printf("Enter the number you want to insert : ");
                scanf("%d", &val);
                newnode->data=val;
                int c=0;
                ptr=head;
                while(c<index-1){
                    ptr=ptr->link;
                    c=c+1;
                }
                newnode->link=ptr->link;
                ptr->link=newnode;
            }
            break;

            // case 2:
            // printf("Enter the number you want to insert : ");
            // scanf("%d", &last);
            // newnode = (struct node *)malloc(sizeof(struct node));
            // newnode->data = last;
            // newnode->link = NULL;
            // // ptr->link=newnode;
            // ptr = head; 
            // while (ptr->link != NULL) {
            //     ptr = ptr->link; 
            // }
            // ptr->link = newnode; 
            // break;   

            case 2:
            printf("Enter the index where you want to delete : ");
            scanf("%d",&index);
            if (head == NULL) {
                printf("List is empty, nothing to delete.\n");
            }
            if(index<0 || index>=num){
                printf("INVALID INDEX");
            } else {
                ptr=head;
                if(index==0){
                    head=head->link;
                    free(ptr);
                    // ptr=NULL;
                }
                else{
                    int c=0;
                    while(c<index-1){
                        ptr=ptr->link;
                        c=c+1;
                    }
                    del=ptr->link;
                    ptr->link=del->link;
                    free(del);
                    // del=NULL;
                }
            }
            break;

            case 3:
            ptr = head;
            while (ptr != NULL) {
                printf("%d\t", ptr->data);
                ptr = ptr->link;
            }
            break;  

            case 4:
            printf("Exiting program");
            break;

            default:
            printf("Invalid choice");
            break;
        }
    }while(choice!=4);

    return 0;
}
