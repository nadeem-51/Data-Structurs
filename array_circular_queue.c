#include <stdio.h>
#define MAX 5   // maximum size of the circular queue

int queue[MAX];
int front = -1;
int rear = -1;

// Function to insert (enqueue) an element into the circular queue
void enqueue(int value) {
    // Check if queue is full
    if ((front == 0 && rear == MAX - 1) || (rear + 1) % MAX == front) {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }

    // First element insertion
    if (front == -1)
        front = 0;

    // Move rear circularly
    rear = (rear + 1) % MAX;
    queue[rear] = value;
    printf("%d enqueued into the circular queue.\n", value);
}

// Function to delete (dequeue) an element from the circular queue
void dequeue() {
    if (front == -1) {
        printf("Queue Underflow! No element to dequeue.\n");
        return;
    }

    printf("%d dequeued from the circular queue.\n", queue[front]);

    // If only one element is left
    if (front == rear) {
        front = rear = -1;
    } else {
        // Move front circularly
        front = (front + 1) % MAX;
    }
}

// Function to view the element at the front of the circular queue
void peek() {
    if (front == -1) {
        printf("Circular Queue is empty.\n");
    } else {
        printf("Front element is: %d\n", queue[front]);
    }
}

// Function to display all elements in the circular queue
void display() {
    if (front == -1) {
        printf("Circular Queue is empty.\n");
        return;
    }

    printf("Circular Queue elements are: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Main function to demonstrate circular queue operations
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
