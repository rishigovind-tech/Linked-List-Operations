#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void printList(struct Node *temp)
{
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}
void insertAtPos(struct Node *temp, int count)
{
    int pos, i = 1;

    printf("\nEnter the position want to insert");
    scanf("%d", &pos);

    while (i < pos)
    {
        temp = temp->next;
        i++;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter the data you want to insert in the end :");
    scanf("%d", &newNode->data);

    newNode->next = NULL;

    newNode->next = temp->next;
    temp->next = newNode;
}

int main()
{
    struct Node *newNode, *head, *temp;
    head = NULL;

    int choice = 1;
    int count = 0;

    while (choice)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter data: ");
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

        count++;

        printf("Do you want to continue(0 or 1):");
        scanf("%d", &choice);
    }

    printf("Count of node %d\n", count);

    temp = head;
    insertAtPos(temp, count);

    temp = head;

    printList(temp);
}