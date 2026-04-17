#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

void enqueue(int value) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));

    temp->data = value;
    temp->next = NULL;

    if (head == NULL && tail == NULL) {
        head = tail = temp;
        tail->next = head;
    }
    else {
        tail->next = temp;
        tail = temp;
        tail->next = head;
    }

    printf("%d inserted\n", value);
}

void dequeue() {
    if (head == NULL && tail == NULL) {
        printf("Queue is Empty\n");
        return;
    }

    struct Node *temp = head;

    if (head == tail) {
        printf("%d deleted\n", temp->data);
        head = tail = NULL;
        free(temp);
    }
    else {
        printf("%d deleted\n", temp->data);
        head = head->next;
        tail->next = head;
        free(temp);
    }
}

void display() {
    if (head == NULL && tail == NULL) {
        printf("Queue is Empty\n");
        return;
    }

    struct Node *current = head;

    printf("Queue: ");

    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);

    printf("(back to %d)\n", head->data);
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
