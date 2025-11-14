#include <stdio.h>
#include <stdlib.h>

// Define structure for a node in the doubly linked list
struct Node {
    int data;
    struct Node* prev;   // pointer to the previous node
    struct Node* next;   // pointer to the next node
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(0);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to create a doubly linked list
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int value;

    for (int i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &value);

        newNode = createNode(value);

        if (head == NULL) {
            head = newNode;  // first node becomes head
        } else {
            temp->next = newNode;  // link new node to current last node
            newNode->prev = temp;  // link back to previous node
        }

        temp = newNode; // move temp to the new last node
    }

    return head;
}

// Function to display the doubly linked list in forward direction
void displayForward(struct Node* head) {
    struct Node* temp = head;

    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("\nDoubly Linked List (forward):\n");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to display the doubly linked list in reverse direction
void displayReverse(struct Node* head) {
    struct Node* temp = head;

    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    // Move to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("\nDoubly Linked List (reverse):\n");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    int n;

    printf("Enter number of nodes in the doubly linked list: ");
    scanf("%d", &n);

    head = createList(n);

    displayForward(head);
    displayReverse(head);

    return 0;
}
