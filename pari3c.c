#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* deleteNode(struct Node* head, int x) {
    if (head == NULL) return NULL;

    struct Node* temp = head;

    if (x == 1) {
        head = temp->next;
        free(temp);
        return head;
    }

    for (int i = 1; temp != NULL && i < x - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        return head;
    }

    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete); 

    return head;
}

void printList(struct Node* head);
struct Node* createListFromArray(int arr[], int n);

int main() {
    int arr[] = {1, 3, 4};
    struct Node* head = createListFromArray(arr, 3);
    
    printf("Original List: ");
    printList(head);

    head = deleteNode(head, 3);
    printf("List after deleting node at position 3: ");
    printList(head);
    
    return 0;
}

void printList(struct Node* head) { while (head) { printf("%d -> ", head->data); head = head->next; } printf("NULL\n"); }
struct Node* createListFromArray(int arr[], int n) {
    if (n == 0) return NULL;
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = arr[0];
    struct Node* curr = head;
    for (int i = 1; i < n; i++) {
        curr->next = (struct Node*)malloc(sizeof(struct Node));
        curr = curr->next;
        curr->data = arr[i];
    }
    curr->next = NULL;
    return head;
}
