#include <stdio.h>
#define MAX 5   // Maximum size of stack

int stack[MAX];
int top = -1;  // Stack is empty initially

// Function to push element into the stack
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d, stack is full.\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed into stack.\n", value);
    }
}

// Function to display the stack elements
void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements (top to bottom): ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int n, value;

    printf("Enter the number of elements to push (max %d): ", MAX);
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        push(value);
    }

    printf("\nFinal Stack:\n");
    display();

    return 0;
}
