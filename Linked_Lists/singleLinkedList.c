/**
 * Program to create and manipulate a singly linked list.
 * 
 * This program performs the following operations:
 * - Initializes a linked list with a single element.
 * - Traverses and counts the elements in the linked list.
 * - Adds elements at the beginning and at the end of the linked list.
 * - Frees the entire linked list to release allocated memory.
 */

#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    int data;
    struct node *link;
};

// Function prototypes
void listTraversing(const struct node *head);
struct node *insertElementAtEnd(struct node *head, int data);
void insertElementAtBeginning(struct node **head, int data);
void insertElementAtPosition(struct node *head, int data, int position);
void freeList(struct node *head);

int main(void) {
    struct node *head = malloc(sizeof(struct node));
    if (!head) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    head->data = 56;
    head->link = NULL;

    // Add elements to the end of the list
    head = insertElementAtEnd(head, 98);
    head = insertElementAtEnd(head, 76);
    head = insertElementAtEnd(head, 100);

    // Add an element to the beginning of the list
    insertElementAtBeginning(&head, 1);
    
    // Add an element at a certain position
    insertElementAtPosition(head, 6, 3);

    // Traverse and print the list
    listTraversing(head);

    // Free all allocated nodes
    freeList(head);

    return 0;
}

// Traverse the list, print each element and count nodes
void listTraversing(const struct node *head) 
{
    int count = 0;
    const struct node *current = head;

    printf("List elements: ");
    while (current != NULL) {
        printf("%d%s", current->data, current->link ? " -> " : "");
        count++;
        current = current->link;
    }
    printf("\nThe number of nodes: %d\n", count);
}

// Insert an element at the end of the list
struct node *insertElementAtEnd(struct node *head, int data) 
{
    struct node *temp = malloc(sizeof(struct node));
    if (!temp) {
        fprintf(stderr, "Memory allocation failed\n");
        return head;
    }
    temp->data = data;
    temp->link = NULL;

    if (!head) 
    {
        // If the list is empty, the new node is the head
        return temp;
    }

    struct node *current = head;
    while (current->link != NULL) 
    {
        current = current->link;
    }
    current->link = temp;

    return head;
}

// Insert an element at the beginning of the list
void insertElementAtBeginning(struct node **head, int data) 
{
    struct node *newElement = malloc(sizeof(struct node));
    if (!newElement) 
    {
        fprintf(stderr, "Memory allocation failed\n");
    }
    newElement->data = data;
    newElement->link = *head;
    *head = newElement;
}

// Inserting a Node at a Certain Position
void insertElementAtPosition(struct node *head, int data, int position) 
{
    struct node *newElement = malloc(sizeof(struct node));
    if (!newElement) 
    {
        fprintf(stderr, "Memory allocation failed\n");
    }

    struct node *current = head;
    int currentPos = 0;

    // Traverse to the node just before the insertion point
    while (currentPos < position - 1) 
    {
        current = current->link;
        currentPos++;
    }
     // Insert the new node at the specified position
    newElement->data = data;
    newElement->link = current->link;
    current->link = newElement;
}

// Free the entire list to avoid memory leaks
void freeList(struct node *head) 
{
    struct node *current = head;
    while (current != NULL) {
        struct node *temp = current;
        current = current->link;
        free(temp);
    }
}
