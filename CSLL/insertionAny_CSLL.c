#include <stdio.h>
#include <stdlib.h>

// Define structure for circular singly linked list node
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

    temp->next = head; // make it circular
    return head;
}

// Function to insert a node at any position
struct Node* insertAtPosition(struct Node* head, int value, int position) {
    struct Node* newNode = createNode(value);

    // Case 1: If list is empty
    if (head == NULL) {
        newNode->next = newNode; // node points to itself
        head = newNode;
        printf("Inserted %d as the first node.\n", value);
        return head;
    }

    // Case 2: Insert at beginning
    if (position == 1) {
        struct Node* temp = head;
        // Find the last node to maintain circular link
        while (temp->next != head) {
            temp = temp->next;
        }

        newNode->next = head;
        temp->next = newNode;
        head = newNode;

        printf("Node with data %d inserted at position 1 (beginning).\n", value);
        return head;
    }

    // Case 3: Insert at given position (middle or end)
    struct Node* temp = head;
    int i = 1;

    // Traverse to node before the desired position
    while (i < position - 1 && temp->next != head) {
        temp = temp->next;
        i++;
    }

    // If position is invalid (greater than list size + 1)
    if (i < position - 1) {
        printf("Invalid position! Insertion not possible.\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Node with data %d inserted at position %d.\n", value, position);
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
    int n, value, position;

    printf("Enter number of nodes in the circular singly linked list: ");
    scanf("%d", &n);

    head = createCircularList(n);

    printf("\nCircular Linked List before insertion:\n");
    displayList(head);

    printf("\nEnter position to insert new node: ");
    scanf("%d", &position);
    printf("Enter data to insert: ");
    scanf("%d", &value);

    head = insertAtPosition(head, value, position);

    printf("\nCircular Linked List after insertion:\n");
    displayList(head);

    return 0;
}
