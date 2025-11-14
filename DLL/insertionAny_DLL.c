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

// Function to display the doubly linked list (forward)
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

// Function to insert a node at any given position
struct Node* insertAtPosition(struct Node* head, int value, int position) {
    struct Node* newNode = createNode(value);

    // Case 1: Insert at beginning
    if (position == 1) {
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        head = newNode;
        printf("Node with data %d inserted at position %d (beginning).\n", value, position);
        return head;
    }

    struct Node* temp = head;
    int i;

    // Traverse to the (position - 1)th node
    for (i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    // If position is invalid (greater than list length + 1)
    if (temp == NULL) {
        printf("Invalid position! Insertion not possible.\n");
        free(newNode);
        return head;
    }

    // Case 2: Insert in between or at end
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;

    printf("Node with data %d inserted at position %d.\n", value, position);
    return head;
}

// Main function
int main() {
    struct Node* head = NULL;
    int n, value, position;

    printf("Enter number of nodes in the doubly linked list: ");
    scanf("%d", &n);

    head = createList(n);

    printf("\nDoubly Linked List before insertion:\n");
    displayList(head);

    printf("\nEnter position to insert new node: ");
    scanf("%d", &position);
    printf("Enter value to insert: ");
    scanf("%d", &value);

    head = insertAtPosition(head, value, position);

    printf("\nDoubly Linked List after insertion:\n");
    displayList(head);

    return 0;
}
