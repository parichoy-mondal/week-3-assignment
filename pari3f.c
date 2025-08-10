#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node {
    int data;
    struct Node* next;
};
bool detectLoop(struct Node* head) {
    struct Node *slow_p = head, *fast_p = head;

    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p) {
            return true;
        }
    }
    return false;
}
int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
    head->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->data = 2;
    head->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->data = 3;
    head->next->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->next->data = 4;
    head->next->next->next->next = head->next;
    printf("Does the list have a loop? %s\n", detectLoop(head) ? "Yes" : "No");
    struct Node* head2 = (struct Node*)malloc(sizeof(struct Node));
    head2->data = 1;
    head2->next = NULL;
    printf("Does the second list have a loop? %s\n", detectLoop(head2) ? "Yes" : "No");
    
    return 0;
}
