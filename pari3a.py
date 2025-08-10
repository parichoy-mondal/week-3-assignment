class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def insert_at_beginning(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def display(self):
        current = self.head
        elements = []
        while current:
            elements.append(current.data)
            current = current.next
        print(" -> ".join(map(str, elements)))

my_list = LinkedList()
my_list.insert_at_beginning(30)
my_list.insert_at_beginning(20)
my_list.insert_at_beginning(10)
my_list.display() # Output: 10 -> 20 -> 30
