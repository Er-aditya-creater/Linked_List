#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
} *START = NULL;

int Count(); // Function Prototype or Function Decleraton

void InsertAtEnd()
{
    struct node *ptr, *temp;
    int key;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Insufficient Space\n");
        return;
    }
    else
    {
        printf("Enter the element you want to insert at end ");
        scanf("%d", &key);
        temp->data = key;
        temp->link = NULL;
        if (START == NULL)
        {
            START = temp;
        }
        else
        {
            ptr = START;
            while (ptr->link != NULL)
            {
                ptr = ptr->link;
            }
            ptr->link = temp;
        }
    }
}

void InsertAtBeg()
{
    struct node *temp;
    int key;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Insufficient Space\n");
    }
    else
    {
        printf("Enter the element you want to insert at Begning ");
        scanf("%d", &key);
        temp->data = key;
        temp->link = START;
        START = temp;
    }
}

void InsertAtIndex()
{
    struct node *ptr, *temp;
    int key, index;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Insufficient Space\n");
    }
    else
    {
        printf("Enter the index at which you want to insert the element ");
        scanf("%d", &index);
        if (index == 1)
        {
            InsertAtBeg();
            return;
        }
        else
        {
            if (index <= Count())
            {
                printf("Enter the element you want to insert ");
                scanf("%d", &key);
                ptr = START;
                for (int i = 0; i < index - 2; i++)
                {
                    ptr = ptr->link;
                }
                temp->data = key;
                temp->link = ptr->link;
                ptr->link = temp;
            }
            else
            {
                printf("Please enter a valid Index!\n");
            }
        }
    }
}

void deleteAtBeg()
{
    struct node *ptr = START;
    if (ptr == NULL)
    {
        printf("Linked List is Empty\n");
    }
    else
    {
        START = ptr->link;
        ptr->link = NULL;
        free(ptr);
    }
}

void deleteAtEnd()
{
    struct node *ptr = START, *temp;
    if (ptr == NULL)
    {
        printf("Linked List is Empty\n");
    }
    else
    {
        if (ptr->link == NULL)
        {
            START = NULL;
            free(ptr);
        }
        else
        {
            // // do{
            // //     ptr = ptr->link;
            // // } while (ptr != NULL);

            // while(ptr->link->link != NULL){
            //     ptr = ptr->link;
            // }
            // ptr->link = NULL;
            for (int i = 0; i < Count() - 2; i++)
            {
                ptr = ptr->link;
            }
            temp = ptr->link;
            ptr->link = NULL;
            free(temp);
        }
    }
}

void deleteAtIndex()
{
    int del;
    struct node *ptr = START, *temp;
    if (ptr == NULL)
    {
        printf("Linkedlist is Empty.\n");
    }
    else
    {
        printf("Please enter the index of node you want to delete ");
        scanf("%d", &del);
        if (del == 1)
        {
            deleteAtBeg();
        }
        else if (del == Count())
        {
            deleteAtEnd();
        }
        else if (del < Count())
        {
            for (int i = 0; i < del - 2; i++)
            {
                ptr = ptr->link;
            }
            temp = ptr->link;
            ptr->link = ptr->link->link;
            free(temp);
        }
        else
        {
            printf("Invalid index.\n");
        }
    }
}

int Count() // Function Defination
{
    struct node *ptr;
    int count = 0;
    ptr = START;
    while (ptr != NULL)
    {
        ptr = ptr->link;
        count++;
    }
    return count;
}

void display()
{
    struct node *ptr;
    ptr = START;
    if (START == NULL)
    {
        printf("Linked list is Empty\n");
    }
    else
    {
        while (ptr->link != NULL)
        {
            printf("%d\t", ptr->data);
            ptr = ptr->link;
        }
        printf("%d\n", ptr->data);
    }
}

// void display(struct node *ptr)
// {
//     if(ptr = NULL){
//         return;
//     }
//     printf("%d\t",ptr->link);
//     display(ptr->link);
// }

int main()
{
    int choice;
    while (1)
    {
        printf("Various Operations on Singly Linked List :\n");
        printf("Enter 1 to insert an element at begning\n");
        printf("Enter 2 to insert an element at ending \n");
        printf("Enter 3 to insert an element at some inde\n");
        printf("Enter 4 to display the Linked List\n");
        printf("Enter 5 to count the elements of Linked List\n");
        printf("Enter 6 to delete an element at begning\n");
        printf("Enter 7 to delete an element at ending\n");
        printf("Enter 8 to delete an element at some index\n");
        printf("Enter 9 to exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            InsertAtBeg();
            break;
        case 2:
            InsertAtEnd();
            break;
        case 3:
            InsertAtIndex();
            break;
        case 4:
            display(START);
            break;
        case 5:
            printf("Length of our Linked List is %d\n", Count()); // Function Call
            break;
        case 6:
            deleteAtBeg();
            break;
        case 7:
            deleteAtEnd();
            break;
        case 8:
            deleteAtIndex();
            break;
        case 9:
            printf("Thank You!\n");
            exit(0);
            break;
        default:
            printf("Please enter a valid number\n");
        }
    }
    return 0;
}