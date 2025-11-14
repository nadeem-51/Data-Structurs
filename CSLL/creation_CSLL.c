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

    // Link last node to head to make it circular
    temp->next = head;

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
    } while (temp != head); // stop when we reach head again

    printf("(back to head)\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    int n;

    printf("Enter number of nodes in the circular singly linked list: ");
    scanf("%d", &n);

    head = createCircularList(n);

    displayList(head);

    return 0;
}
