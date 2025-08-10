def reverse_list(self):
    prev = None
    current = self.head
    while current:
        next_node = current.next
        current.next = prev
        prev = current
        current = next_node
    self.head = prev

llist = SinglyLinkedList()
llist.insert_at_end(1)
llist.insert_at_end(2)
llist.insert_at_end(3)
llist.insert_at_end(4)
print("Original Linked List:")
llist.print_list()

llist.reverse_list()
print("Reversed Linked List:")
llist.print_list()
