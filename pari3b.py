class Node:

    def __init__(self, data):
        self.data = data
        self.next = None

def insertAtMid(head, x):

    if(head == None):
        head = Node(x)
    else:

        newNode = Node(x)

        ptr = head
        length = 0

        while(ptr != None):
            ptr = ptr.next
            length += 1

        if(length % 2 == 0):
            count = length / 2 
        else:
            (length + 1) / 2

        ptr = head

        while(count > 1):
            count -= 1
            ptr = ptr.next

        newNode.next = ptr.next
        ptr.next = newNode

def display(head):
    temp = head
    while(temp != None):
        print(str(temp.data), end = " ")
        temp = temp.next

head = Node(1)
head.next = Node(2)
head.next.next = Node(4)
head.next.next.next = Node(5)

print("Linked list before insertion: ", end = "")
display(head)

x = 3
insertAtMid(head, x)

print("Linked list after insertion: " , end = "")
display(head)

