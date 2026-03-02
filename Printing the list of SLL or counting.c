#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
// Function to count the number of nodes in SLL
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head; 
    while (temp != NULL) {
        count++;
        temp = temp->next; 
    }
    return count;
}
// Function to display the SLL
void displayNodes(struct Node* head) {
    struct Node* current = head;
    printf("Singly Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }     printf("NULL\n"); }
// Main function
int main() {
    struct Node* head = NULL;
    struct Node* temp;
    struct Node* current;
    // Manually creating and linking nodes
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = 410;
    temp->next = NULL;
    head = temp; 
    current = temp; 

    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = 420;
    temp->next = NULL;
    current->next = temp;
    current = temp;

    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = 430;
    temp->next = NULL;
    current->next = temp;

    printf("Original List:\n");
    displayNodes(head);

    printf("Number of nodes in the list: %d\n", countNodes(head));
    return 0;
}
