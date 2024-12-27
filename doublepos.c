#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

int main()
{
    struct Node *newNode, *temp, *head,*tail;
    head = NULL;

    int choice = 1;
    int data;

    while (choice)
    {

        printf("Enter the Data ");
        scanf("%d", &data);

        newNode = (struct Node *)malloc(sizeof(struct Node));

        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (head == NULL)
        {
            temp = head = newNode;
        }
        else
        {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
        tail=temp;

        printf("Do you want to continue (0 OR 1) ");
        scanf("%d", &choice);
    }

    temp = head;

    int pos, i = 1;

    printf("\nEnter the position want to insert");
    scanf("%d", &pos);

    while (i < pos)
    {
        temp = temp->next;
        i++;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter the data you want to insert in the end :");
    scanf("%d", &newNode->data);

    newNode->next = NULL;
    newNode->prev = NULL;

    newNode->next = temp->next;
    temp->next = newNode;
    newNode->prev = temp;

    temp = head;

    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}