#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};

int main()
{
    struct node *head = NULL, *newnode, *ptr;
    int num, value;
    printf("No. of elements you want to store in a linked list : ");
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter element %d : ", i + 1);
        scanf("%d", &value);
        newnode->data = value;
        newnode->link = NULL;

        if (head == NULL)
        {
            head = newnode;
            ptr = head;
        }
        else
        {
            ptr->link = newnode;
            ptr = newnode;
        }
    }
    // ptr = head;
    // while (ptr != NULL)
    // {
    //     printf("%d\t", ptr->data);
    //     ptr = ptr->link;
    // }

    int choice,first,last;
    do {
        printf("\n*****MENU*****\n");
        printf("Enter 1 to insert at begenning\nEnter 2 to insert at last\nEnter 3 to display linked list\nEnter 4 to exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the number you want to insert : ");
            scanf("%d", &first);
            newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data = first;
            newnode->link = head;
            head = newnode;
            ptr = head;
            break;

        case 2:
            printf("Enter the number you want to insert : ");
            scanf("%d", &last);
            newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data = last;
            newnode->link = NULL;
            ptr = head; 
            while (ptr->link != NULL) {
                ptr = ptr->link; 
            }
            ptr->link = newnode; 
            break;

        case 3:
            ptr = head;
            while (ptr != NULL)
            {
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
    } while(choice!=4);

    return 0;
}
