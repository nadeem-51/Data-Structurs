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

// Function to delete a node at any position
struct Node* deleteAtPosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return head;
    }

    struct Node* temp = head;
    int count = 1;

    // Case 1: Deletion at beginning
    if (position == 1) {
        // Only one node in the list
        if (head->next == head) {
            printf("Node with data %d deleted. List is now empty.\n", head->data);
            free(head);
            return NULL;
        }

        struct Node* last = head->prev; // last node
        head = head->next;
        head->prev = last;
        last->next = head;

        printf("Node with data %d deleted from position 1 (beginning).\n", temp->data);
        free(temp);
        return head;
    }

    // Traverse to the node at given position
    while (count < position && temp->next != head) {
        temp = temp->next;
        count++;
    }

    // Invalid position
    if (count < position) {
        printf("Invalid position! Deletion not possible.\n");
        return head;
    }

    // Case 2: Deletion at end
    if (temp->next == head) {
        struct Node* prev = temp->prev;
        prev->next = head;
        head->prev = prev;
        printf("Node with data %d deleted from the end.\n", temp->data);
        free(temp);
        return head;
    }

    // Case 3: Deletion in the middle
    struct Node* prevNode = temp->prev;
    struct Node* nextNode = temp->next;

    prevNode->next = nextNode;
    nextNode->prev = prevNode;

    printf("Node with data %d deleted from position %d.\n", temp->data, position);
    free(temp);

    return head;
}

// Main function
int main() {
    struct Node* head = NULL;
    int n, position;

    printf("Enter number of nodes in the doubly circular linked list: ");
    scanf("%d", &n);

    head = createDoublyCircularList(n);

    printf("\nDoubly Circular Linked List before deletion:\n");
    displayForward(head);

    printf("\nEnter position to delete: ");
    scanf("%d", &position);

    head = deleteAtPosition(head, position);

    printf("\nDoubly Circular Linked List after deletion:\n");
    displayForward(head);

    return 0;
}
