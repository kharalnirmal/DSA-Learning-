#include <stdio.h>
#include <stdlib.h>

// Structure definition for stack
struct stack {
    int size;  // Maximum size of the stack
    int top;   // Index of the topmost element
    int *s;    // Pointer to dynamically allocated array
};

// Function to create a stack
void create(struct stack *st) {
    printf("Enter size: ");
    scanf("%d", &st->size); // Read the stack size from user
    st->top = -1;  // Initialize stack as empty
    st->s = (int*)malloc(st->size * sizeof(int));  // Allocate memory dynamically
}

// Function to display stack elements
void display(struct stack st) {
    if (st.top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements:\n");
    for (int i = st.top; i >= 0; i--) {
        printf("%d\n", st.s[i]);  // Print elements from top to bottom
    }
}

// Function to push an element onto the stack
void push(struct stack *st, int x) {
    if (st->top == st->size - 1)  // Check for overflow
        printf("Stack overflow\n");
    else {
        st->s[++st->top] = x;  // Increment top and insert element
    }
}

// Function to pop an element from the stack
int pop(struct stack *st) {
    if (st->top == -1) {  // Check for underflow
        printf("Stack underflow\n");
        return -1;
    }
    return st->s[st->top--];  // Return top element and decrement top
}

// Function to check if the stack is empty
int isEmpty(struct stack st) {
    return (st.top == -1);
}

// Function to check if the stack is full
int isFull(struct stack st) {
    return (st.top == st.size - 1);
}

// Function to return the top element of the stack
int stackTop(struct stack st) {
    if (!isEmpty(st))
        return st.s[st.top];
    return -1;  // Return -1 if stack is empty
}

// Function to peek an element at a specific position from the top
int peek(struct stack st, int index) {
    int pos = st.top - index + 1; // Convert index into array position
    if (pos < 0) {
        printf("Invalid position\n");
        return -1;
    }
    return st.s[pos];
}

// Main function to demonstrate stack operations
int main() {
    struct stack st; // Declare stack
    create(&st);  // Create stack with user-defined size
    
    // Push elements onto the stack
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    push(&st, 50);
    
    // Display stack
    display(st);
    
    // Pop an element
    printf("Popped element: %d\n", pop(&st));
    
    // Display stack after pop
    display(st);
    
    // Peek at 2nd element from top
    printf("Peek (2nd from top): %d\n", peek(st, 2));
    
    // Check if stack is empty
    printf("Is stack empty? %s\n", isEmpty(st) ? "Yes" : "No");
    
    // Check if stack is full
    printf("Is stack full? %s\n", isFull(st) ? "Yes" : "No");
    
    return 0;
}
