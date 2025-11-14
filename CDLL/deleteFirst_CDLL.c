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

// Function to delete the first node
struct Node* deleteAtBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return head;
    }

    // Case 1: Only one node
    if (head->next == head) {
        printf("Node with data %d deleted. List is now empty.\n", head->data);
        free(head);
        head = NULL;
        return head;
    }

    // Case 2: More than one node
    struct Node* temp = head;
    struct Node* last = head->prev;

    head = head->next;           // Move head to second node
    head->prev = last;           // Update new head’s prev pointer
    last->next = head;           // Update last node’s next pointer

    printf("Node with data %d deleted from the beginning.\n", temp->data);
    free(temp);

    return head;
}

// Main function
int main() {
    struct Node* head = NULL;
    int n;

    printf("Enter number of nodes in the doubly circular linked list: ");
    scanf("%d", &n);

    head = createDoublyCircularList(n);

    printf("\nDoubly Circular Linked List before deletion:\n");
    displayForward(head);

    head = deleteAtBeginning(head);

    printf("\nDoubly Circular Linked List after deletion:\n");
    displayForward(head);

    return 0;
}
