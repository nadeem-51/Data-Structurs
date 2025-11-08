#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Front and Rear pointers to represent the queue
struct Node* front = NULL;
struct Node* rear = NULL;

// Function to add (enqueue) an element to the queue
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed! Queue Overflow.\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) { // Queue is empty
        front = rear = newNode;
    } else {
        rear->next = newNode; // Link new node at the end
        rear = newNode;       // Move rear pointer to the new node
    }

    printf("%d enqueued into the queue.\n", value);
}

// Function to remove (dequeue) an element from the queue
void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow! No element to dequeue.\n");
        return;
    }

    struct Node* temp = front;
    printf("%d dequeued from the queue.\n", front->data);
    front = front->next; // Move front to the next node
    free(temp);

    if (front == NULL) { // If queue becomes empty
        rear = NULL;
    }
}

// Function to view the element at the front of the queue
void peek() {
    if (front == NULL) {
        printf("Queue is empty.\n");
    } else {
        printf("Front element is: %d\n", front->data);
    }
}

// Function to display all elements in the queue
void display() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node* temp = front;
    printf("Queue elements are: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to demonstrate queue operations
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Queue Menu (Linked List Implementation) ---\n");
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
