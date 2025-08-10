#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

struct Node {
    int data;
    struct Node* next;
};
bool searchKey(struct Node* head, int x) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == x) {
            return true;
        }
        current = current->next;
    }
    return false;
}

struct Node* createListFromArray(int arr[], int n);

int main() {
    int arr[] = {1, 2, 3, 4};
    struct Node* head = createListFromArray(arr, 4);

    int key1 = 3;
    printf("Searching for %d: %s\n", key1, searchKey(head, key1) ? "Found" : "Not Found");

    int key2 = 5;
    printf("Searching for %d: %s\n", key2, searchKey(head, key2) ? "Found" : "Not Found");

    return 0;
}

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
