def delete_node(self, key):
    temp = self.head

    if temp and temp.data == key:
        self.head = temp.next
        temp = None
        return

    prev = None
    while temp and temp.data != key:
        prev = temp
        temp = temp.next

    if temp is None:
        return

    prev.next = temp.next
    temp = None

list = SinglyLinkedList()
list.insert_at_end(10)
list.insert_at_end(20)
list.insert_at_end(30)
list.insert_at_end(40)
print("Original Linked List:")
list.print_list()

list.delete_node(30)
print("Linked List after deleting node with key 30:")
list.print_list()

list.delete_node(10)
print("Linked List after deleting head node with key 10:")
list.print_list()
