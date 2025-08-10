def get_nth_from_end(self, n):
    if self.head is None:
        return None
    
    main_ptr = self.head
    ref_ptr = self.head
    count = 0

    while count < n:
        if ref_ptr is None:
            print("N is larger than the number of nodes.")
            return None
        ref_ptr = ref_ptr.next
        count += 1

    while ref_ptr:
        main_ptr = main_ptr.next
        ref_ptr = ref_ptr.next
        
    return main_ptr.data

llist = SinglyLinkedList()
llist.insert_at_end(1)
llist.insert_at_end(2)
llist.insert_at_end(3)
llist.insert_at_end(4)
llist.insert_at_end(5)
print("Linked List:")
llist.print_list()

n = 2
print(f"The {n}nd node from the end is:", llist.get_nth_from_end(n))

n = 5
print(f"The {n}th node from the end is:", llist.get_nth_from_end(n))
