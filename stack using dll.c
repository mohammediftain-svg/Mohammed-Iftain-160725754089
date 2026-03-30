#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL, *temp;

// PUSH
void push(int x)
{
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->prev = NULL;
    temp->next = head;

    if(head != NULL)
        head->prev = temp;

    head = temp;
}

// POP
void pop()
{
    if(head == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }

    temp = head;
    printf("Deleted: %d\n", temp->data);
    head = head->next;

    if(head != NULL)
        head->prev = NULL;

    free(temp);
}

// Display
void display()
{
    struct Node *current = head;
    while(current != NULL)
    {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main()
{
    int choice, x;

    while(1)
    {
        printf("\n--- STACK using DLL ---\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d",&x);
                push(x);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
        }
    }
}
