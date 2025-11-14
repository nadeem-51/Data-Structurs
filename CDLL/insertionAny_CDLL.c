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

// Function to insert a node at any position
struct Node* insertAtPosition(struct Node* head, int value, int position) {
    struct Node* newNode = createNode(value);

    // Case 1: Empty list
    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        printf("Inserted %d as the first node.\n", value);
        return head;
    }

    // Case 2: Insert at the beginning
    if (position == 1) {
        struct Node* last = head->prev;

        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
        head = newNode;

        printf("Node with data %d inserted at position 1 (beginning).\n", value);
        return head;
    }

    // Case 3: Insert at middle or end
    struct Node* temp = head;
    int i = 1;

    // Traverse to the node before the desired position
    while (i < position - 1 && temp->next != head) {
        temp = temp->next;
        i++;
    }

    // If position is invalid (greater than length + 1)
    if (i < position - 1) {
        printf("Invalid position! Insertion not possible.\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;

    printf("Node with data %d inserted at position %d.\n", value, position);
    return head;
}

// Function to display the list forward
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

// Function to display the list backward
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
    int n, value, position;

    printf("Enter number of nodes in the doubly circular linked list: ");
    scanf("%d", &n);

    head = createDoublyCircularList(n);

    printf("\nDoubly Circular Linked List before insertion:\n");
    displayForward(head);

    printf("\nEnter position to insert new node: ");
    scanf("%d", &position);
    printf("Enter value to insert: ");
    scanf("%d", &value);

    head = insertAtPosition(head, value, position);

    printf("\nDoubly Circular Linked List after insertion:\n");
    displayForward(head);
    displayBackward(head);

    return 0;
}
