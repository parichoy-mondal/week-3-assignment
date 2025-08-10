#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* head); 

void removeLoop(struct Node* head) {
    if (head == NULL || head->next == NULL) return;

    struct Node *slow = head, *fast = head;

    slow = slow->next;
    fast = fast->next->next;
    while (fast && fast->next) {
        if (slow == fast) break;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (slow == fast) {
        slow = head;
        if (slow == fast) {
             while(fast->next != slow) fast = fast->next;
        } else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        fast->next = NULL;
    }
}
int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
    head->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->data = 2;
    head->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->data = 3;
    head->next->next->next = head->next; 

    printf("List has a loop. Removing it...\n");
    removeLoop(head);
    printf("List after removing loop: ");
    printList(head);

    return 0;
}
void printList(struct Node* head) { while (head) { printf("%d -> ", head->data); head = head.next; } printf("NULL\n"); }
