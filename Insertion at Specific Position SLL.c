#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *temp, *head, *current;

/* Function: Insert at specific position */
void insertPosition(int x, int pos)
{
    int i;

    temp = (struct Node*) malloc(sizeof(struct Node));

    temp->data = x;
    temp->next = NULL;

    if (pos == 1)
    {
        temp->next = head;
        head = temp;
        return;
    }

    current = head;

    for (i = 1; i < pos - 1 && current != NULL; i++)
    {
        current = current->next;
    }
    if (current == NULL)
    {
        printf("Invalid Position\n");
        free(temp);
        return;
    }

    temp->next = current->next;
    current->next = temp;
}

/* Display list */
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

    insertPosition(10, 1);
    insertPosition(20, 2);
    insertPosition(30, 3);

    printf("Initial List:\n");
    display();

    printf("\nEnter position to insert new node: ");
    scanf("%d", &pos);

    insertPosition(99, pos);

    printf("List after insertion:\n");
    display();

    return 0;
}
