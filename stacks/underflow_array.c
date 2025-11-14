#include <stdio.h>
#define MAX 5   // Maximum size of stack

int stack[MAX];
int top = -1;

// Function to push element into stack
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d, stack is full.\n", value);
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
        printf("Stack elements are: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    pop();              // Underflow here (stack is empty)
    push(10);
    push(20);
    push(30);
    display();

    pop();
    pop();
    pop();
    pop();              // Underflow again (after all elements removed)

    return 0;
}
