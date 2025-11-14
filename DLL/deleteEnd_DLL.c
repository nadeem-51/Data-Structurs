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

// Function to delete the last node from the doubly linked list
struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return head;
    }

    struct Node* temp = head;

    // If there is only one node
    if (head->next == NULL) {
        printf("Node with data %d deleted from end.\n", head->data);
        free(head);
        head = NULL;
        return head;
    }

    // Traverse to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // temp now points to the last node
    printf("Node with data %d deleted from end.\n", temp->data);

    temp->prev->next = NULL; // unlink last node
    free(temp);              // free memory of last node

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

// Main function
int main() {
    struct Node* head = NULL;
    int n;

    printf("Enter number of nodes in the doubly linked list: ");
    scanf("%d", &n);

    head = createList(n);

    printf("\nDoubly Linked List before deletion:\n");
    displayList(head);

    head = deleteAtEnd(head);

    printf("\nDoubly Linked List after deletion:\n");
    displayList(head);

    return 0;
}
