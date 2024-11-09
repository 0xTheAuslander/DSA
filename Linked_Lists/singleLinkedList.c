/**
 * Program to create and manipulate a singly linked list.
 * 
 * This program performs the following operations:
 * - Initializes a linked list with a single element.
 * - Traverses and counts the elements in the linked list.
 * - Adds elements at the beginning, end, and a specified position.
 * - Deletes elements from the beginning and end.
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
struct node *del_first(struct node *head);
void del_last(struct node **head);
void deleteElementAtPosition(struct node **head, int position); 
void del_entire_list(struct node **head); 
void freeList(struct node *head);

int main(void) {
    // Initialize linked list with one element
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
    head = insertElementAtEnd(head, 37);
    head = insertElementAtEnd(head, 20);
    head = insertElementAtEnd(head, 34);

    // Add an element to the beginning of the list
    insertElementAtBeginning(&head, 1);
    
    // Add an element at a certain position
    insertElementAtPosition(head, 6, 3);

    // Traverse and print the list
    listTraversing(head);

    // Delete the first node
    head = del_first(head);

    // Delete the last node
    del_last(&head);
    
    // Delete the last node
    deleteElementAtPosition(&head, 4);

    // Traverse and print the list
    listTraversing(head);

    // Delete entire liste
    del_entire_list(&head);
    listTraversing(head);
    if (head == NULL)
        printf("Linked List deleted succesfully!\n");
    
    // Free all allocated nodes
    freeList(head);

    return 0;
}

// Traverse the list, print each element, and count nodes
void listTraversing(const struct node *head) {
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
struct node *insertElementAtEnd(struct node *head, int data) {
    // Allocate memory for the new node
    struct node *temp = malloc(sizeof(struct node));
    if (!temp) {
        fprintf(stderr, "Memory allocation failed\n");
        return head;
    }
    temp->data = data;
    temp->link = NULL;

    // If the list is empty, the new node is the head
    if (!head) {
        return temp;
    }

    // Traverse to the last node
    struct node *current = head;
    while (current->link != NULL) {
        current = current->link;
    }
    current->link = temp;

    return head;
}

// Insert an element at the beginning of the list
void insertElementAtBeginning(struct node **head, int data) {
    // Allocate memory for the new node
    struct node *newElement = malloc(sizeof(struct node));
    if (!newElement) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    newElement->data = data;
    newElement->link = *head;
    *head = newElement;
}

// Insert a node at a specified position
void insertElementAtPosition(struct node *head, int data, int position) {
    // Allocate memory for the new node
    struct node *newElement = malloc(sizeof(struct node));
    if (!newElement) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    // Set data for the new node
    newElement->data = data;

    struct node *current = head;
    int currentPos = 0;

    // Traverse to the node just before the insertion point
    while (current != NULL && currentPos < position - 1) {
        current = current->link;
        currentPos++;
    }

    // Check if we reached the desired position or if the position is out of range
    if (current == NULL) {
        fprintf(stderr, "Position out of range\n");
        free(newElement);
        return;
    }

    // Insert the new node at the specified position
    newElement->link = current->link;
    current->link = newElement;
}

// Delete the first node
struct node *del_first(struct node *head) {
    // Check if the list is empty
    if (head == NULL) {
        printf("List is already empty\n");
        return NULL;
    }

    // Point head to the next node and free the first node
    struct node *temp = head;
    head = head->link;
    free(temp);

    return head;
}

// Delete the last node
void del_last(struct node **head) {
    // Check if the list is empty
    if (*head == NULL) {
        printf("List is already empty\n");
        return;
    }

    // If the list has only one node
    if ((*head)->link == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    // Traverse to the second-to-last node
    struct node *temp = *head;
    while (temp->link->link != NULL) {
        temp = temp->link;
    }

    // Free the last node and update the link of the second-to-last node
    free(temp->link);
    temp->link = NULL;
}

// Delete a node at a particular position
void deleteElementAtPosition(struct node **head, int position) 
{
    struct node *current = *head;
    struct node *previous = *head;
    int currentPos = 0;

    if (*head == NULL) {
        printf("List is already empty\n");
        return;
    }
    else if (position == 1)
    {
        *head = current->link;
        free(current);
        current = NULL;
    }
    else
    {
        while (current != NULL && currentPos < position - 1) 
        {
            previous = current;
            current = current->link;
            currentPos++;
        }
        previous->link = current->link;
        free(current);
        current = NULL;
    }
}


// Delete the entire single linked list
void del_entire_list(struct node **head) 
{
    // Check if the list is empty
    if (*head == NULL) {
        printf("List is already empty\n");
        return;
    }

    // If the list has only one node
    if ((*head)->link == NULL) {
        
        *head = NULL;
        return;
    }

    // Traverse to the second-to-last node
    struct node *temp = *head;
    while (temp != NULL) 
    {
        temp = temp->link;
        free(*head);
        *head = temp;
    }
}

// Free the entire list to avoid memory leaks
void freeList(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        struct node *temp = current;
        current = current->link;
        free(temp);
    }
}
