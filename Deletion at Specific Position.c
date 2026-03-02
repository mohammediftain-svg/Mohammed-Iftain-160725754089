#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head, *current, *prev;

void deletePosition(int pos)
{
    int i;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (pos == 1)
    {
        current = head;
        head = head->next;
        free(current);
        return;
    }

    current = head;

    for (i = 1; i < pos && current != NULL; i++)
    {
        prev = current;
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Invalid Position\n");
        return;
    }

    prev->next = current->next;
    free(current);
}

void insertEnd(int x)
{
    struct Node *newNode, *temp;

    newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    if (head == NULL)
        head = newNode;
    else
    {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void display()
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main()
{
    int pos;

    head = NULL;

    insertEnd(999);
    insertEnd(998);
    insertEnd(997);
    insertEnd(996);

    printf("Initial List:\n");
    display();

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    deletePosition(pos);

    printf("After deletion:\n");
    display();

    return 0;
}
