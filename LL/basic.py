class ListNode:
	def __init__(self, val): # Constructor to initialize the node object
		self.val = val
		self.next = None

class LinkedList:
	def __init__(self): # Constructor to initialize head
		self.head = None

	def insertAtStart(self, node):
		new_node = ListNode(node) 
		new_node.next = self.head # Make next of new node as head 
		self.head = new_node # move the head to point to the new node

	def insertAfter(self, prev, node):
		if prev == None:
			return
		new_node = ListNode(node)
		new_node.next = prev.next
		prev.next = new_node		

	def deleteNode(self, node):
		temp = self.head # store head node

		# If head node itself holds the key to be deleted 
		if temp is not None and temp.val == node:
				self.head = temp.next # change head
				temp = None	# free old head
				return 

		# Search for the key to be deleted, keep track of the 
		# previous node as we need to change 'prev.next' 
		while temp is not None and temp.data != node:
			prev = temp
			temp = temp.next

		# if key was not present in linked list
		if temp == None:
			return

		#unlink the node from LL
		prev.next = temp.next
		temp = None				

	def deleteNodeAtPos(self, pos):
		if self.head == None: # if LL is empty
			return

		temp = self.head # Store head node

		# if head need to be removed
		if pos == 0:	
			self.head = temp.next
			temp = None
			return

		# Find previous node of the node to be deleted
		for i in range(pos-1 ): 
			temp = temp.next
			if temp is None: 
				break	

		# if pos is more than no of nodes
		if temp is None or temp.next is None:
			return	

		next = temp.next.next
		temp.next = None # free memory
		temp.next = next	

	def append(self, node):
		new_node = ListNode(node)
		last = self.head

		# If the Linked List is empty, then make the new node as head 
		if self.head == None:
			self.head = new_node
			return

		while(last.next != None): # traverse till the last node
			last = last.next

		last.next = new_node # Change the next of last node
		return	


	def search(self, li, key):
		if li == None:
			return False
		if li.val == key:
			return True
		return self.search(li.next, key)

	def printList(self):
		temp = self.head
		while(temp):
			print("%d" %(temp.val), end = " ")	
			temp = temp.next
		print(" ")	

if __name__ == '__main__':
	llist = LinkedList()
	llist.insertAtStart(6)
	llist.insertAtStart(4)
	llist.insertAtStart(3)
	llist.insertAtStart(2)
	llist.insertAtStart(1)
	llist.printList()
	llist.append(7)
	llist.printList()
	llist.insertAtStart(0)
	llist.printList()
	llist.insertAfter(llist.head.next.next.next.next, 5) # insert after 4
	llist.deleteNode(0)
	llist.printList()
	llist.deleteNodeAtPos(5)
	llist.printList()
	if llist.search(llist.head, 3) == True:
		print("yes")
	else:
		print("no")	