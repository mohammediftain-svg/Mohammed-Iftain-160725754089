#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL, *rear = NULL, *temp;


void enqueue(int x)
{
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;

    if(front == NULL)
        front = rear = temp;
    else
    {
        rear->next = temp;
        rear = temp;
    }
}


void dequeue()
{
    if(front == NULL)
    {
        printf("Queue Underflow\n");
        return;
    }

    temp = front;
    printf("Deleted: %d\n", temp->data);
    front = front->next;

    if(front == NULL)
        rear = NULL;

    free(temp);
}


void display()
{
    struct Node *current = front;
    while(current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main()
{
    int choice, x;

    while(1)
    {
        printf("\n--- QUEUE using SLL ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d",&x);
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
        }
    }
}
