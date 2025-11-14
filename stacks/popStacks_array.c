#include <stdio.h>
#define MAX 5   // Maximum size of stack

int stack[MAX];
int top = -1;  // Stack initially empty

// Function to push element into stack
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d.\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed into stack.\n", value);
    }
}

// Function to pop element from stack
void pop() {
    if (top == -1) {
        printf("Stack Underflow! Cannot pop, stack is empty.\n");
    } else {
        int value = stack[top];
        top--;
        printf("%d popped from stack.\n", value);
    }
}

// Function to display stack elements
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
    push(10);
    push(20);
    push(30);
    push(40);
    display();

    pop();
    pop();
    display();

    pop();
    pop();
    pop();  // This will cause underflow

    return 0;
}
