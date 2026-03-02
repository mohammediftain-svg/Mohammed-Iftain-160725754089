#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;

void insertBeginning(int x)
{
    struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head;
    temp->prev = NULL;

    if (head != NULL)
        head->prev = temp;

    head = temp;
}

void insertEnd(int x)
{
    struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;

    if (head == NULL)
    {
        temp->prev = NULL;
        head = temp;
        return;
    }

    struct Node *current = head;
    while (current->next != NULL)
        current = current->next;

    current->next = temp;
    temp->prev = current;
}
void insertPosition(int x, int pos)
{
    int i;
    struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = x;

    if (pos == 1)
    {
        temp->next = head;
        temp->prev = NULL;
        if (head != NULL)
            head->prev = temp;
        head = temp;
        return;
    }

    struct Node *current = head;
    for (i = 1; i < pos - 1 && current != NULL; i++)
        current = current->next;

    if (current == NULL)
    {
        printf("Invalid position\n");
        free(temp);
        return;
    }

    temp->next = current->next;
    temp->prev = current;

    if (current->next != NULL)
        current->next->prev = temp;

    current->next = temp;
}

void deleteBeginning()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    free(temp);
}

void deleteEnd()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *current = head;

    if (current->next == NULL) // Only one node
    {
        head = NULL;
        free(current);
        return;
    }

    while (current->next != NULL)
        current = current->next;

    current->prev->next = NULL;
    free(current);
}

/* Function to delete at specific position */
void deletePosition(int pos)
{
    int i;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *current = head;

    if (pos == 1)
    {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(current);
        return;
    }

    for (i = 1; i < pos && current != NULL; i++)
        current = current->next;

    if (current == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    if (current->next != NULL)
        current->next->prev = current->prev;

    if (current->prev != NULL)
        current->prev->next = current->next;

    free(current);
}

void displayForward()
{
    struct Node *current = head;
    printf("Forward: ");
    while (current != NULL)
    {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void displayBackward()
{
    struct Node *current = head;
    if (current == NULL)
    {
        printf("Backward: NULL\n");
        return;
    }

    while (current->next != NULL)
        current = current->next;

    printf("Backward: ");
    while (current != NULL)
    {
        printf("%d <-> ", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}

int main()
{
    int choice, value, pos;

    do
    {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete at position\n");
        printf("7. Display forward\n");
        printf("8. Display backward\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBeginning(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertPosition(value, pos);
                break;
            case 4:
                deleteBeginning();
                break;
            case 5:
                deleteEnd();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deletePosition(pos);
                break;
            case 7:
                displayForward();
                break;
            case 8:
                displayBackward();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }

    } while (choice != 0);

    return 0;
}
