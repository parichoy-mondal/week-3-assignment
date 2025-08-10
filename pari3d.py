def search(self, key):
    current = self.head
    while current:
        if current.data == key:
            return True
        current = current.next
    return False

llist = SinglyLinkedList()
llist.insert_at_end(1)
llist.insert_at_end(5)
llist.insert_at_end(9)
llist.insert_at_end(13)
print("Linked List:")
llist.print_list()

print("Is 9 in the list?", llist.search(9))
print("Is 7 in the list?", llist.search(7))
