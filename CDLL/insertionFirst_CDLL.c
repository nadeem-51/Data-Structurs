#include <stdio.h>
#include <stdlib.h>

// Define structure for a doubly circular linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(0);
    }
    newNode->data = value;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

// Function to create a doubly circular linked list
struct Node* createDoublyCircularList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int value;

    for (int i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &value);
        newNode = createNode(value);

        if (head == NULL) {
            head = newNode;
            head->next = head;
            head->prev = head;
            temp = head;
        } else {
            newNode->prev = temp;
            newNode->next = head;
            temp->next = newNode;
            head->prev = newNode;
            temp = newNode;
        }
    }
    return head;
}

// Function to insert at beginning of doubly circular linked list
struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    // Case 1: Empty list
    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        printf("Node with data %d inserted as the first node.\n", value);
        return head;
    }

    // Case 2: Non-empty list
    struct Node* last = head->prev;  // last node in the list

    newNode->next = head;
    newNode->prev = last;

    head->prev = newNode;
    last->next = newNode;

    head = newNode;  // update head to new node

    printf("Node with data %d inserted at the beginning.\n", value);
    return head;
}

// Function to display list forward
void displayForward(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("\nDoubly Circular Linked List (forward):\n");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

// Function to display list backward
void displayBackward(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head->prev;
    printf("\nDoubly Circular Linked List (backward):\n");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    } while (temp != head->prev);
    printf("(back to tail)\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    int n, value;

    printf("Enter number of nodes in the doubly circular linked list: ");
    scanf("%d", &n);

    head = createDoublyCircularList(n);

    printf("\nDoubly Circular Linked List before insertion:\n");
    displayForward(head);

    printf("\nEnter value to insert at the beginning: ");
    scanf("%d", &value);

    head = insertAtBeginning(head, value);

    printf("\nDoubly Circular Linked List after insertion:\n");
    displayForward(head);
    displayBackward(head);

    return 0;
}
