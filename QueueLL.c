#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct node {
    int data;
    struct node *next;
};

// Global pointers to keep track of the head and rear of the queue
struct node *head = NULL;
struct node *rear = NULL;

// Function to check if the queue is empty
int isEmpty() {
    return head == NULL;
}

// Function to add a value to the queue
void enqueue(int value) {
    struct node *nn = (struct node*)malloc(sizeof(struct node));
    nn->data = value;
    nn->next = NULL;

    // If the queue is empty, initialize both head and rear to the new node
    if (isEmpty()) {
        head = nn;
        rear = nn;
    } else {
        // Link the new node at the end and update rear
        rear->next = nn;
        rear = nn;
    }
}

// Function to remove a value from the queue
int dequeue() {
    if (isEmpty()) {
        printf("\nQueue Underflow\n");
        return -1;
    }

    struct node *temp = head;
    int dequeuedValue = temp->data;
    head = head->next; // Move head to the next node

    // Free the removed node
    free(temp);

    // If the queue becomes empty, update rear to NULL as well
    if (head == NULL) {
        rear = NULL;
    }

    return dequeuedValue;
}

// Function to get the value at the front of the queue
int Front() {
    if (isEmpty()) {
        printf("\nQueue is empty\n");
        return -1;
    }

    return head->data;
}

// Function to display all elements in the queue
void display() {
    struct node *temp = head;

    if (isEmpty()) {
        printf("\nQueue is empty\n");
        return;
    }

    printf("\nQueue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next; // Move to the next node
    }
    printf("\n");
}

// Main function to demonstrate the queue operations
int main() {
    int choice, value;

    do {
        printf("\n\n---MENU---\n\n");
        printf("1. Enqueue\n2. Dequeue\n3. Front\n4. Display\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter value to be enqueued: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                if (isEmpty())
                    printf("\nQueue Underflow\n");
                else
                    printf("\nDequeued: %d\n", dequeue());
                break;

            case 3:
                if (isEmpty())
                    printf("\nQueue is empty\n");
                else
                    printf("\nValue at front: %d\n", Front());
                break;

            case 4:
                display();
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("\nInvalid input\n");
                break;
        }

    } while (choice != 0);

    return 0;
}
