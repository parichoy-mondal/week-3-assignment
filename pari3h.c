#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next; 
        current->next = prev; 
        prev = current;       
        current = next;
    }
    head = prev;
    return head;
}

void printList(struct Node* head);
struct Node* createListFromArray(int arr[], int n);

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    struct Node* head = createListFromArray(arr, 5);
    
    printf("Original list: ");
    printList(head);
    
    head = reverseList(head);
    
    printf("Reversed list: ");
    printList(head);

    return 0;
}

