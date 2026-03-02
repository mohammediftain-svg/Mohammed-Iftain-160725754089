#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};


struct Node *temp, *head, *current;

/* Function: Insert node at end */
void insertEnd(int x)
{

    temp = (struct Node*) malloc(sizeof(struct Node));


    temp->data = x;
    temp->next = NULL;


    if (head == NULL)
    {
        head = temp;
    }
    else
    {

        current = head;

  
        while (current->next != NULL)
        {
            current = current->next;
        }

        current->next = temp;
        current = temp;
    }
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

    head = NULL;

    insertEnd(810);
    insertEnd(209);
    insertEnd(370);

    printf("Linked List after insertion at end:\n");
    display();

    return 0;
}
