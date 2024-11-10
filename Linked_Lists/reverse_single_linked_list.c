#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

// Function prototypes
struct node* createNode(int data);
struct node* addElementAtEnd(struct node *head, int data);
void displayList(struct node *head);
void freeList(struct node *head);
void reverse_linked_list(struct node **head);

int main() {
    struct node *head = NULL;

    // Adding 9 elements to the list
    for (int i = 1; i <= 9; i++) {
        head = addElementAtEnd(head, i);
    }

    // Display the original list
    printf("Original list:\n");
    displayList(head);

    // Reverse the list
    reverse_linked_list(&head);

    // Display the reversed list
    printf("Reversed list:\n");
    displayList(head);

    // Free the list
    freeList(head);

    return 0;
}

// Function to create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

// Function to add a node at the end of the list
struct node* addElementAtEnd(struct node *head, int data) {
    struct node *newNode = createNode(data);

    if (head == NULL) {
        return newNode;  // If list is empty, new node is the head
    }

    struct node *current = head;
    while (current->link != NULL) {
        current = current->link;
    }
    current->link = newNode;
    return head;
}

// Function to display the list
void displayList(struct node *head) {
    struct node *current = head;
    printf("List elements: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->link;
    }
    printf("NULL\n");
}

// Function to free the list
void freeList(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        struct node *temp = current;
        current = current->link;
        free(temp);
    }
}

// Function to reverse the linked list
void reverse_linked_list(struct node **head) {
    struct node *prev = NULL;
    struct node *current = *head;
    struct node *next = NULL;

    while (current != NULL) {
        next = current->link;  // Store the next node
        current->link = prev;  // Reverse the current node's link
        prev = current;        // Move prev to current
        current = next;        // Move current to next
    }
    *head = prev;  // Update head to the new front of the list
}