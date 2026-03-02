
 
int q[max], f = -1, r = -1;
void insert(int value) {
    if (r == max - 1) {
        printf("Overflow\n");
    } else {
        if (f == -1)
            f = 0;
        q[++r] = value;
        printf("%d inserted\n", value);
    }
}
void delet() {
    if (f == -1 || f > r) {
        printf("Underflow\n");
    } else {
        printf("%d deleted\n", q[f++]);
        if (f > r)
            f = r = -1;
    }
}
void display() {
    if (f == -1 || f > r) {
        printf("Queue is empty\n");
    } else {
        printf("Elements are: ");
        for (int i = f; i <= r; i++) {
            printf("%d ", q[i]);
        }
        printf("\n");
    }
}
int main() {
    int c, x;
    do {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &c);
        switch (c) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                insert(x);
                break;
            case 2:
                delet();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exit\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (c != 4);
}

