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
            head = newNode;  // first node
        } else {
            temp->next = newNode;  // link new node to previous
        }
        temp = newNode;
    }

    return head;
}

// Function to delete the last node
struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return head;
    }

    // If the list has only one node
    if (head->next == NULL) {
        printf("Node with data %d deleted from end.\n", head->data);
        free(head);
        head = NULL;
        return head;
    }

    // Traverse to the second last node
    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    // temp now points to second last node
    printf("Node with data %d deleted from end.\n", temp->next->data);
    free(temp->next);     // delete last node
    temp->next = NULL;    // make second last node the new end

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
    int n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    head = createList(n);

    printf("\nLinked list before deletion:\n");
    displayList(head);

    head = deleteAtEnd(head);

    printf("\nLinked list after deletion:\n");
    displayList(head);

    return 0;
}
