def remove_loop(self):
    if self.head is None or self.head.next is None:
        return
        
    slow_ptr = self.head
    fast_ptr = self.head

    while fast_ptr and fast_ptr.next:
        slow_ptr = slow_ptr.next
        fast_ptr = fast_ptr.next.next
        if slow_ptr == fast_ptr:
            break

    if slow_ptr != fast_ptr:
        return

    slow_ptr = self.head
    while slow_ptr.next != fast_ptr.next:
        slow_ptr = slow_ptr.next
        fast_ptr = fast_ptr.next

    fast_ptr.next = None

llist = SinglyLinkedList()
llist.insert_at_end(1)
llist.insert_at_end(2)
llist.insert_at_end(3)
llist.insert_at_end(4)
llist.insert_at_end(5)

llist.head.next.next.next.next.next = llist.head.next.next
print("Loop detected:", llist.detect_loop())

llist.remove_loop()
print("Loop detected after removal:", llist.detect_loop())

print("List after removing loop:")
llist.print_list()
