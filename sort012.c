#include <stdio.h>
#include <stdlib.h>
 
struct Node
{
    int data;
    struct Node* next;
};
 
void push(struct Node** head, int data)
{
    // create a new linked list node from the heap
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
 
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}
 
void printList(struct Node* head)
{
    struct Node* ptr = head;
    while (ptr)
    {
        printf("%d —> ", ptr->data);
        ptr = ptr->next;
    }
 
    printf("NULL");
}
 
void sortList(struct Node** head)
{
   
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
 
   
    struct Node dummyZero, dummyOne, dummyTwo;
    dummyZero.next = dummyOne.next = dummyTwo.next = NULL;
 
    
    struct Node* zero = &dummyZero, *one = &dummyOne, *two = &dummyTwo;
    struct Node* curr = *head;
 
    while (curr != NULL)
    {
        if (curr->data == 0)
        {
            zero->next = curr;
            zero = zero->next;
        }
        else if (curr->data == 1)
        {
            one->next = curr;
            one = one->next;
        }
        else {
            two->next = curr;
            two = two->next;
        }
        curr = curr->next;
    }
 
    zero->next = (dummyOne.next)? (dummyOne.next): (dummyTwo.next);
    one->next = dummyTwo.next;
    two->next = NULL;
 
    *head = dummyZero.next;
}
 
int main(void)
{
    int keys[] = { 1, 2, 0, 0, 1, 2, 1, 2, 0};
    int n = sizeof(keys) / sizeof(keys[0]);
 
    struct Node* head = NULL;
    for (int i = n - 1; i >= 0; i--) {
        push(&head, keys[i]);
    }
 
    sortList(&head);
    printList(head);
 
    return 0;
}
