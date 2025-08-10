#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertInMiddle(struct Node* head, int x) {
    if (head == NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = NULL;
        return newNode;
    }

    struct Node* slow = head;
    struct Node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = slow->next;
    slow->next = newNode;

    return head;
}

void printList(struct Node* head);
struct Node* insertAtEnd(struct Node* head, int x); 

int main() {
    struct Node* head1 = NULL;
    head1 = insertAtEnd(head1, 1);
    head1 = insertAtEnd(head1, 2);
    head1 = insertAtEnd(head1, 4);
    head1 = insertAtEnd(head1, 5);
    printf("Original List 1: ");
    printList(head1);
    head1 = insertInMiddle(head1, 3);
    printf("Modified List 1: ");
    printList(head1);

    return 0;
}

void printList(struct Node* head) {
    while (head != NULL) { printf("%d -> ", head->data); head = head->next; }
    printf("NULL\n");
}
struct Node* insertAtEnd(struct Node* head, int x) {
    struct Node* nn = (struct Node*)malloc(sizeof(struct Node));
    nn->data = x; nn->next = NULL;
    if (head == NULL) return nn;
    struct Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = nn;
    return head;
}
