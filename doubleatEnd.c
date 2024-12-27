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

    printf("%d",tail->data);

    newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data want to insert ");
    scanf("%d", &data);
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

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
