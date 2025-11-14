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

    temp->next = head;  // make the list circular
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

// Function to delete a node at any given position
struct Node* deleteAtPosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return head;
    }

    struct Node* temp = head;

    // Case 1: Delete the first node
    if (position == 1) {
        // If there's only one node
        if (head->next == head) {
            printf("Node with data %d deleted. List is now empty.\n", head->data);
            free(head);
            head = NULL;
            return head;
        }

        // Otherwise, find the last node
        struct Node* last = head;
        while (last->next != head)
            last = last->next;

        head = head->next;   // move head to next node
        last->next = head;   // last node now points to new head

        printf("Node with data %d deleted from position 1 (beginning).\n", temp->data);
        free(temp);
        return head;
    }

    // Case 2: Delete node at given position (middle or end)
    struct Node* prev = NULL;
    int i = 1;

    while (i < position && temp->next != head) {
        prev = temp;
        temp = temp->next;
        i++;
    }

    // If position is invalid
    if (i < position) {
        printf("Invalid position! Deletion not possible.\n");
        return head;
    }

    prev->next = temp->next;  // unlink the node
    printf("Node with data %d deleted from position %d.\n", temp->data, position);
    free(temp);

    return head;
}

// Main function
int main() {
    struct Node* head = NULL;
    int n, position;

    printf("Enter number of nodes in the circular singly linked list: ");
    scanf("%d", &n);

    head = createCircularList(n);

    printf("\nCircular Linked List before deletion:\n");
    displayList(head);

    printf("\nEnter position to delete: ");
    scanf("%d", &position);

    head = deleteAtPosition(head, position);

    printf("\nCircular Linked List after deletion:\n");
    displayList(head);

    return 0;
}
