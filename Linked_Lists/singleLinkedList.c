/**
 * Create a single linked list
 * traverse the linked list to count the number of elements and access datat
 * add element at the end of the linked list
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node 
{
    int data;
    struct node *link;
};

void listTraversing(struct node *head);
struct node *insertElementAtEnd(struct node *ptr, int data);

int main(void)
{
    struct node *head = malloc(sizeof(struct node));
    head->data = 56;
    head->link = NULL;

    struct node *ptr = head;

    ptr = insertElementAtEnd(ptr, 98);
    ptr = insertElementAtEnd(ptr, 76);
    ptr = insertElementAtEnd(ptr, 100);

    listTraversing(head);

    ptr = head;
    // Traverse to the last node
    while (ptr->link != NULL) {
        ptr = ptr->link;
    }
    
    // Freeing all allocated nodes
    struct node *ptrx = head;
    while (ptrx != NULL) {
        struct node *temp = ptrx;
        ptrx = ptrx->link;
        free(temp);
    }
}

void listTraversing(struct node *head)
{
    if (!head)
        printf("Linked list is empty\n");
    struct node *ptr = head;

    int count = 0;
    printf("List elements: ");
    while (ptr != NULL)
    {
        if (count > 0)
            printf(", ");
        printf("%d", ptr->data);

        count++;
        ptr = ptr->link;
    }
    printf("\nThe number of nodes: %d\n", count);
}

struct node *insertElementAtEnd(struct node *ptr, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    ptr->link = temp;  // Link last node to the new node
    return temp;
}