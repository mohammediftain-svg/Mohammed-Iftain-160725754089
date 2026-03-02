
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head, *temp;

void deleteBeginning()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);
}
void insertEnd(int x)
{
    struct Node *newNode, *current;

    newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    if (head == NULL)
        head = newNode;
    else
    {
        current = head;
        while (current->next != NULL)
            current = current->next;
        current->next = newNode;
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
    head = NULL;

    insertEnd(170);
    insertEnd(820);
    insertEnd(630);

    printf("Before deletion:\n");
    display();

    deleteBeginning();

    printf("After deletion at beginning:\n");
    display();

    return 0;
}
