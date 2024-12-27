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
    printf("NULL");
}

void deleteData(struct Node **head, int input)
{
    // struct Node *temp, *prev;

    // temp = prev = head;

    // while (temp != NULL)
    // {

    //     if (head->data==input&& temp->data==input)
    //     {
    //         head=head->next;
    //         free(temp);
    //         break;
    //     }

    //     if (temp->data == input)
    //     {
    //         prev->next = temp->next;
    //         break;
    //     }
    //     // free(temp);
    //     prev = temp;
    //     temp = temp->next;
    // }
    // // free(temp);

    struct Node *temp = *head;
    struct Node *prev=*head;

    // If the node to delete is the head node
    if (temp != NULL && temp->data == input)
    {
        *head = temp->next; // Move head to the next node
        free(temp);          // Free the old head
        return;
    }

    // Traverse the list to find the node with the value
    while (temp != NULL && temp->data != input)
    {
        prev = temp;
        temp = temp->next;
    }

    // If the value is found, delete the node
    if (temp != NULL)
    {
        prev->next = temp->next;
        free(temp);
    }
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

    int input;
    printf("Enter the data which want to delete: ");
    scanf("%d", &input);

    deleteData(&head, input);
    print(head);
}