#include<stdio.h>
#include<stdlib.h>

// Define the structure for a node in the queue
struct Node{
    int data;           // Data part to store the value
    struct Node *next;  // Pointer to the next node in the queue
};

// Global pointers for the front and rear of the queue
struct Node *front = NULL, *rear = NULL;

// Function to enqueue (add) an element to the queue
void enqueue(int x) {
    // Create a new node dynamically
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    
    // Check if memory allocation fails
    if(t == NULL) {
        printf("Queue is full");  // Handle full queue (memory error)
    } else {
        t->data = x;       // Assign the data to the new node
        t->next = NULL;    // Set next to NULL as it's the last node

        // If the queue is empty (both front and rear are NULL)
        if(front == NULL) {
            front = rear = t;  // Set both front and rear to the new node
        } else {
            rear->next = t;    // Point the current rear to the new node
            rear = t;          // Update rear to the new node
        }
    }
}

// Function to dequeue (remove) an element from the queue
int dequeue() {
    int x = -1;   // Initialize the variable to store dequeued data
    struct Node *t;  // Temporary pointer for the node to be deleted
    
    // Check if the queue is empty (front is NULL)
    if(front == NULL) {
        printf("Queue is empty");  // Handle empty queue
    } else {
        x = front->data;   // Store the data of the front node (to be dequeued)
        t = front;         // Temporary pointer to the front node
        front = front->next;  // Move front pointer to the next node
        free(t);               // Free memory of the dequeued node
    }
    
    return x;  // Return the dequeued data
}

// Function to display the queue
void Display() {
    struct Node *p = front;  // Start from the front of the queue
    
    // Traverse through the queue and print the data of each node
    while(p) {
        printf("%d ", p->data);  // Print the data of the current node
        p = p->next;             // Move to the next node in the queue
    }
    
    printf("\n");  // Print a newline at the end of the display
}

// Main function to demonstrate the queue operations
int main() {
    enqueue(10);  // Enqueue 10
    enqueue(20);  // Enqueue 20
    enqueue(30);  // Enqueue 30
    enqueue(40);  // Enqueue 40
    enqueue(50);  // Enqueue 50
    
    Display();  // Display the current queue
    
    printf("dequeue: %d \n", dequeue());  // Dequeue an element and print it
    
    Display();  // Display the queue after dequeue
    
    return 0;  // End of program
}
