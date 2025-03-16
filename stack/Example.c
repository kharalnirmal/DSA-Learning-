#include <stdio.h> 
#include <stdlib.h>  // Added for malloc() and free()

// Define a structure for the Node of the stack
struct Node {
    int data; // Data part of the node
    struct Node *next; // Pointer to the next node
};

struct Node *top = NULL;  // Pointer to the top node of the stack

// Function to push an element onto the stack
void push(int x) {
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for new node
    
    if (t == NULL) // Check if memory allocation fails
        printf("Stack is full\n");
    else {
        t->data = x; // Assign data to the new node
        t->next = top; // Link new node to the previous top node
        top = t; // Update top to the new node
    }
}

// Function to pop an element from the stack
int pop() {
    struct Node *t;
    int x = -1; // Default value in case stack is empty

    if (top == NULL) // Check if stack is empty
        printf("Stack is empty\n");
    else {
        t = top; // Store the top node temporarily
        top = top->next; // Move top to the next node
        x = t->data; // Retrieve data from the node to be deleted
        free(t); // Free the memory of the deleted node
    }
    return x; // Return popped element
}

// Function to display all elements of the stack
void Display() {
    struct Node *p = top; // Pointer to traverse the stack
    while (p != NULL) { // Loop until end of stack
        printf("%d ", p->data); // Print data of current node
        p = p->next; // Move to next node
    }
    printf("\n"); // Newline for better output formatting
}

int main() {
    push(10); // Push 10 onto the stack
    push(20); // Push 20 onto the stack
    push(30); // Push 30 onto the stack
    push(40); // Push 40 onto the stack
    
    Display(); // Display stack elements
    
    printf("%d\n", pop()); // Pop and print top element of the stack
    
    return 0; // Indicate successful program termination
}
