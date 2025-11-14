#include <stdio.h>
#include <stdlib.h>

// Define structure for a circular singly linked list node
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

// Function to create a circular singly linked list
struct Node* createCircularList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int value;

    for (int i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &value);

        newNode = createNode(value);

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Make the list circular
    temp->next = head;

    return head;
}

// Function to insert a node at the end of circular singly linked list
struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        newNode->next = newNode;  // single node points to itself
        head = newNode;
        printf("Node with data %d inserted as the first node.\n", value);
        return head;
    }

    struct Node* temp = head;

    // Traverse until we reach the last node (which points back to head)
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;    // last node points to new node
    newNode->next = head;    // new node points back to head

    printf("Node with data %d inserted at the end.\n", value);
    return head;
}

// Function to display the circular singly linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("\nCircular Singly Linked List elements are:\n");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    int n, value;

    printf("Enter number of nodes in the circular singly linked list: ");
    scanf("%d", &n);

    head = createCircularList(n);

    printf("\nCircular Linked List before insertion:\n");
    displayList(head);

    printf("\nEnter value to insert at the end: ");
    scanf("%d", &value);

    head = insertAtEnd(head, value);

    printf("\nCircular Linked List after insertion:\n");
    displayList(head);

    return 0;
}
