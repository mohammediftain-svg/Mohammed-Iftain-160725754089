#include <stdio.h>
#include <stdlib.h>


struct Node
{
    int data;
    struct Node *next;
};


struct Node *temp, *head, *current;

/* Function to insert node at end */
void createNode(int X)
{
    
    temp = (struct Node*) malloc(sizeof(struct Node));
    
    
    temp->data = X;
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

/* Function to display list */
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

    int n, i, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("Enter value %d: ", i);
        scanf("%d", &value);
        createNode(value);
    }

    printf("Linked List: ");
    display();

    return 0;
}
