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

        if (head == NULL)
            head = newNode;
        else
            temp->next = newNode;

        temp = newNode;
    }
    return head;
}

// Function to display the linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to concatenate two linked lists
struct Node* concatenate(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;  // If first list is empty
    if (head2 == NULL) return head1;  // If second list is empty

    struct Node* temp = head1;
    while (temp->next != NULL) {      // Traverse to end of first list
        temp = temp->next;
    }
    temp->next = head2;               // Link end of first list to start of second
    return head1;                     // Return new head
}

// Main function
int main() {
    struct Node *head1 = NULL, *head2 = NULL, *concatenated = NULL;
    int n1, n2;

    printf("Enter number of nodes in first linked list: ");
    scanf("%d", &n1);
    head1 = createList(n1);

    printf("\nEnter number of nodes in second linked list: ");
    scanf("%d", &n2);
    head2 = createList(n2);

    printf("\nFirst linked list:\n");
    displayList(head1);

    printf("\nSecond linked list:\n");
    displayList(head2);

    concatenated = concatenate(head1, head2);

    printf("\nConcatenated linked list:\n");
    displayList(concatenated);

    return 0;
}
