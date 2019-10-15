class TreeNode:
	def __init__(self, key):
		self.left = None
		self.right = None
		self.val = key

def Inorder(root):
	if root == None:
		return
	Inorder(root.left)
	print(root.val, end = " ")
	Inorder(root.right)

def Preorder(root):
	if root == None:
		return
	print(root.val, end = " ")
	Preorder(root.left)
	Preorder(root.right)	

def Postorder(root):
	if root == None:
		return
	Postorder(root.left)
	Postorder(root.right)	
	print(root.val, end = " ")		

if __name__ == '__main__':
	root = TreeNode(1)
	root.left = TreeNode(2)
	root.right = TreeNode(3)
	root.left.left = TreeNode(4)
	root.left.right = TreeNode(5)	

	print("inorder traversal", end = " ")
	Inorder(root)
	print("")

	print("Preorder traversal", end = " ")
	Preorder(root)
	print("")

	print("Postorder traversal", end = " ")
	Postorder(root)
	print("")