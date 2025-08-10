#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* reverseList(struct Node* head) {
    struct Node *prev = NULL, *current = head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

struct Node* addTwoLists(struct Node* first, struct Node* second) {
    first = reverseList(first);
    second = reverseList(second);

    int carry = 0;
    struct Node* sum_list_rev = NULL;
    while (first != NULL || second != NULL || carry != 0) {
        int sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
        carry = sum / 10;
        sum = sum % 10;
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = sum;
        newNode->next = sum_list_rev;
        sum_list_rev = newNode;

        if (first) first = first->next;
        if (second) second = second->next;
    }

    return sum_list_rev;
}
void printList(struct Node* head);
struct Node* createListFromArray(int arr[], int n);

int main() {
    int arr1[] = {4, 5};
    int arr2[] = {3, 4, 5};
    struct Node* l1 = createListFromArray(arr1, 2);
    struct Node* l2 = createListFromArray(arr2, 3);
    
    printf("List 1 (45): "); printList(l1);
    printf("List 2 (345): "); printList(l2);
    
    struct Node* sum_list = addTwoLists(l1, l2);
    
    printf("Sum List (390): ");
    printList(sum_list);
    
    return 0;
}
void printList(struct Node* head) { while (head) { printf("%d -> ", head->data); head = head->next; } printf("NULL\n"); }
struct Node* createListFromArray(int arr[], int n) { if (n == 0) return NULL; struct Node* head = (struct Node*)malloc(sizeof(struct Node)); head->data = arr[0]; struct Node* curr = head; for (int i = 1; i < n; i++) { curr->next = (struct Node*)malloc(sizeof(struct Node)); curr = curr->next; curr->data = arr[i]; } curr->next = NULL; return head; }
