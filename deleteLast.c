#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void print(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
}
void deleteAtPos(struct Node *head){
    struct Node *temp,*prev;
    temp=head;
    int pos=2,i=1;
    while (i<pos)
    {
        prev=temp;
        temp=temp->next;
        i++;
    }

    prev->next=temp->next;
    free(temp);
    

}
void deleteAtEnd(struct Node **head)
{
    struct Node *temp = *head;
    struct Node *prevEle;
    while (temp->next != NULL)
    {
        prevEle=temp;
        temp = temp->next;
    }

    free(temp); 
    prevEle->next = NULL;
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

    deleteAtPos(head);

    print(head);

    printf("NULL");
}
