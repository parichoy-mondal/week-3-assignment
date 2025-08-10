def add_two_lists(l1_head, l2_head):
    dummy_head = Node(0)
    current = dummy_head
    p1, p2 = l1_head, l2_head
    carry = 0
    
    while p1 or p2 or carry:
        val1 = p1.data if p1 else 0
        val2 = p2.data if p2 else 0
        
        total_sum = val1 + val2 + carry
        carry = total_sum // 10
        new_digit = total_sum % 10
        
        current.next = Node(new_digit)
        current = current.next
        
        if p1: p1 = p1.next
        if p2: p2 = p2.next
        
    return dummy_head.next

l1 = SinglyLinkedList()
l1.insert_at_end(1)
l1.insert_at_end(2)
l1.insert_at_end(3)

l2 = SinglyLinkedList()
l2.insert_at_end(5)
l2.insert_at_end(6)
l2.insert_at_end(4)

print("List 1:", end=" ")
l1.print_list()
print("List 2:", end=" ")
l2.print_list()

sum_head = add_two_lists(l1.head, l2.head)
sum_list = SinglyLinkedList()
sum_list.head = sum_head
print("Sum List:", end=" ")
sum_list.print_list() 
