#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
struct Node {
    int data;
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
    newNode->next = NULL;
    return newNode;
}

// Function to create a linked list
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int value;

    for (int i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &value);

        newNode = createNode(value);

        if (head == NULL) {
            head = newNode; // first node
        } else {
            temp->next = newNode; // link to previous
        }
        temp = newNode;
    }

    return head;
}

// Function to delete a node from any position
struct Node* deleteAtPosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return head;
    }

    struct Node* temp = head;

    // If deleting the first node
    if (position == 1) {
        head = head->next;
        printf("Node with data %d deleted from position %d.\n", temp->data, position);
        free(temp);
        return head;
    }

    // Traverse to the node before the position
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    // If position is invalid
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position! Deletion not possible.\n");
        return head;
    }

    // Node to delete
    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next; // bypass the deleted node

    printf("Node with data %d deleted from position %d.\n", nodeToDelete->data, position);
    free(nodeToDelete);

    return head;
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;

    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("The linked list elements are:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    int n, position;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    head = createList(n);

    printf("\nLinked list before deletion:\n");
    displayList(head);

    printf("\nEnter the position to delete: ");
    scanf("%d", &position);

    head = deleteAtPosition(head, position);

    printf("\nLinked list after deletion:\n");
    displayList(head);

    return 0;
}
