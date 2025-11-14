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

// Function to display the doubly linked list
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

// Function to delete a node at any given position
struct Node* deleteAtPosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return head;
    }

    struct Node* temp = head;

    // Case 1: Delete the first node
    if (position == 1) {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;

        printf("Node with data %d deleted from position 1.\n", temp->data);
        free(temp);
        return head;
    }

    // Traverse to the node to delete
    for (int i = 1; temp != NULL && i < position; i++) {
        temp = temp->next;
    }

    // If position is invalid
    if (temp == NULL) {
        printf("Invalid position! Deletion not possible.\n");
        return head;
    }

    // Case 2: Delete the last node
    if (temp->next == NULL) {
        temp->prev->next = NULL;
        printf("Node with data %d deleted from the end.\n", temp->data);
        free(temp);
        return head;
    }

    // Case 3: Delete a middle node
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    printf("Node with data %d deleted from position %d.\n", temp->data, position);
    free(temp);

    return head;
}

// Main function
int main() {
    struct Node* head = NULL;
    int n, position;

    printf("Enter number of nodes in the doubly linked list: ");
    scanf("%d", &n);

    head = createList(n);

    printf("\nDoubly Linked List before deletion:\n");
    displayList(head);

    printf("\nEnter the position to delete: ");
    scanf("%d", &position);

    head = deleteAtPosition(head, position);

    printf("\nDoubly Linked List after deletion:\n");
    displayList(head);

    return 0;
}
