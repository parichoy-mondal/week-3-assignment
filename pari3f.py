def detect_loop(self):
    slow_ptr = self.head
    fast_ptr = self.head
    
    while fast_ptr and fast_ptr.next:
        slow_ptr = slow_ptr.next
        fast_ptr = fast_ptr.next.next
        if slow_ptr == fast_ptr:
            return True
            
    return False

llist = SinglyLinkedList()
llist.insert_at_end(10)
llist.insert_at_end(20)
llist.insert_at_end(30)
llist.insert_at_end(40)
llist.insert_at_end(50)

llist.head.next.next.next.next.next = llist.head.next.next

print("Detecting loop in a looped list:", llist.detect_loop())

llist2 = SinglyLinkedList()
llist2.insert_at_end(10)
llist2.insert_at_end(20)
llist2.insert_at_end(30)
print("Detecting loop in a non-looped list:", llist2.detect_loop())
