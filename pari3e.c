#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int getNthFromLast(struct Node* head, int n) {
    if (head == NULL) {
        return -1;
    }
    
    struct Node* main_ptr = head;
    struct Node* ref_ptr = head;
    for (int count = 0; count < n; count++) {
        if (ref_ptr == NULL) {
            // n is greater than the number of nodes
            return -1;
        }
        ref_ptr = ref_ptr->next;
    }

    while (ref_ptr != NULL) {
        main_ptr = main_ptr->next;
        ref_ptr = ref_ptr->next;
    }
    
    return main_ptr->data;
}

struct Node* createListFromArray(int arr[], int n);

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    struct Node* head = createListFromArray(arr, 9);
    
    int n = 2;
    printf("%dth node from last is: %d\n", n, getNthFromLast(head, n));
    
    n = 5;
    printf("%dth node from last is: %d\n", n, getNthFromLast(head, n));

    n = 10;
    printf("%dth node from last is: %d\n", n, getNthFromLast(head, n));
    
    return 0;
}
