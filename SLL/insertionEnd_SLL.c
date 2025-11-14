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

// Function to create an initial linked list
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int value;

    for (int i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &value);

        newNode = createNode(value);

        if (head == NULL) {
            head = newNode;  // first node
        } else {
            temp->next = newNode; // link new node
        }
        temp = newNode;
    }

    return head;
}

// Function to insert a node at the end of the linked list
struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    // If the list is empty
    if (head == NULL) {
        head = newNode;
        printf("Node with data %d inserted as the first node.\n", value);
        return head;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {  // move to last node
        temp = temp->next;
    }

    temp->next = newNode;  // link new node at end
    printf("Node with data %d inserted at the end.\n", value);

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
    int n, value;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    head = createList(n);

    printf("\nLinked list before insertion:\n");
    displayList(head);

    printf("\nEnter value to insert at the end: ");
    scanf("%d", &value);

    head = insertAtEnd(head, value);

    printf("\nLinked list after insertion:\n");
    displayList(head);

    return 0;
}
