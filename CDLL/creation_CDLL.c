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
            // First node
            head = newNode;
            head->next = head;
            head->prev = head;
            temp = head;
        } else {
            // Add to the end
            newNode->prev = temp;
            newNode->next = head;  // link new node to head
            temp->next = newNode;  // link old last node to new node
            head->prev = newNode;  // head's previous becomes new node
            temp = newNode;
        }
    }
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

    struct Node* temp = head->prev;  // start from last node
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
    int n;

    printf("Enter the number of nodes in the doubly circular linked list: ");
    scanf("%d", &n);

    head = createDoublyCircularList(n);

    displayForward(head);
    displayBackward(head);

    return 0;
}
