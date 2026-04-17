#include <stdio.h>

#define SIZE 5

int Q[SIZE];
int front = -1;
int rear = -1;
void display() {
    if (front == -1) {
        printf("Queue is EMPTY\n");
        return;
    }

    int i = front;
    printf("Queue elements: ");

    while (1) {
        printf("%d ", Q[i]);

        if (i == rear)
            break;

        i = (i + 1) % SIZE;
    }
    printf("\n");
}
void enqueue(int value) {

    if ((rear + 1) % SIZE == front) {
        printf("Queue is FULL\n");
        return;
    }

    if (front == -1) {   
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }

    Q[rear] = value;
    printf("Inserted: %d\n", value);

    display();  // display after insertion
}
void dequeue() {

    if (front == -1) {
        printf("Queue is EMPTY\n");
        return;
    }
 int value = Q[front];

    if (front == rear) {           front = -1;
        rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }

    printf("Deleted: %d\n", value);

    display();  
}
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    printf("\n--- Dequeue Operations ---\n");

    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();

    return 0;
}
