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

// Function to delete the first node
struct Node* deleteAtBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return head;
    }

    struct Node* temp = head;

    // If there is only one node
    if (head->next == head) {
        printf("Node with data %d deleted. List is now empty.\n", head->data);
        free(head);
        head = NULL;
        return head;
    }

    // Find the last node (points to head)
    struct Node* last = head;
    while (last->next != head) {
        last = last->next;
    }

    // Adjust pointers
    head = head->next;       // move head to second node
    last->next = head;       // last node points to new head
    printf("Node with data %d deleted from beginning.\n", temp->data);
    free(temp);              // delete old head

    return head;
}

// Main function
int main() {
    struct Node* head = NULL;
    int n;

    printf("Enter number of nodes in the circular singly linked list: ");
    scanf("%d", &n);

    head = createCircularList(n);

    printf("\nCircular Linked List before deletion:\n");
    displayList(head);

    head = deleteAtBeginning(head);

    printf("\nCircular Linked List after deletion:\n");
    displayList(head);

    return 0;
}
