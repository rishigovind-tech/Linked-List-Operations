#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void enterData(struct Node *temp){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("\nEnter the data you want to insert in the end :");
    scanf("%d", &newNode->data);

    newNode->next = NULL;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(struct Node *temp)
{
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int main()
{
    struct Node *newNode, *head, *temp;
    head = NULL;

    int choice = 1;

    while (choice)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data :");
        scanf("%d", &newNode->data);

        newNode->next = NULL;

        if (head == NULL)
        {

            temp = head = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }

        printf("Do you want to continue(0 or 1):");
        scanf("%d", &choice);
    }

    temp = head;

    printList(temp);
    temp=head;
    enterData(temp);

    temp = head;

    printList(temp);
}
