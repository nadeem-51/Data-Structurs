#include <stdio.h>
#include <stdlib.h>

// Define structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
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

        if (head == NULL)
            head = newNode;
        else {
            temp->next = newNode;
            newNode->prev = temp;
        }

        temp = newNode;
    }

    return head;
}

// Function to insert a node at the end of the doubly linked list
struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    // If the list is empty
    if (head == NULL) {
        head = newNode;
        printf("Node with data %d inserted as the first node.\n", value);
        return head;
    }

    struct Node* temp = head;

    // Traverse to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Link the new node at the end
    temp->next = newNode;
    newNode->prev = temp;

    printf("Node with data %d inserted at the end.\n", value);
    return head;
}

// Function to display the doubly linked list in forward direction
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("\nDoubly Linked List (forward):\n");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    int n, value;

    printf("Enter the number of nodes in the doubly linked list: ");
    scanf("%d", &n);

    head = createList(n);

    printf("\nDoubly Linked List before insertion:\n");
    displayList(head);

    printf("\nEnter value to insert at the end: ");
    scanf("%d", &value);

    head = insertAtEnd(head, value);

    printf("\nDoubly Linked List after insertion:\n");
    displayList(head);

    return 0;
}
