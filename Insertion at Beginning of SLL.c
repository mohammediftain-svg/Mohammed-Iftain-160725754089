#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};


struct Node *temp, *head;

/* Function: Insert node at beginning */
void insertBeginning(int x)
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
     
        temp->next = head;

   
        head = temp;
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

    insertBeginning(130);
    insertBeginning(520);
    insertBeginning(8810);

    printf("Linked List after insertion at beginning:\n");
    display();

    return 0;
}
