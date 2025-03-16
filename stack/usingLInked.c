#include <stdio.h>
#include <stdlib.h>  // Added for malloc() and free()

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;  // Pointer to top node

void push(int x) {
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node));
    
    if (t == NULL)
        printf("Stack is full\n");
    else {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop() {
    struct Node *t;
    int x = -1;

    if (top == NULL)
        printf("Stack is empty\n");
    else {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

void Display() {
    struct Node *p = top;
    while (p != NULL) {
        printf("%d ", p->data); // Added space for better output
        p = p->next;
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    
    Display();
    
    printf("%d\n", pop()); // Fixed missing semicolon and added newline for clarity
    
    return 0; // Added return statement
}
