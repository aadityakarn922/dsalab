class Node:
    def __init__(self,data):
        self.data=data
        self.left=None
        self.right=None

def build_tree():
    x=int(input("enter the root"))

  
    if x==-1:
        return None

    root=Node(x)
    print(f"Enter left child of {x}")
    root.left = build_tree()

    print(f"Enter right child of {x}")
    root.right = build_tree()

    return root

def count_nodes(root):
    if root is None:
        return 0

    return 1 + count_nodes(root.left) + count_nodes(root.right)


def preorder(root):
    if root is not None:
        print(root.data)
        preorder(root.left)
        preorder(root.right)

def inorder(root):
    if root is not None:
            inorder(root.left)
            print(root.data)
            inorder(root.right)

def postorder(root):
    if root is not None:
        postorder(root.left)
        postorder(root.right)
        print(root.data)

root = build_tree()

print("Total Nodes:", count_nodes(root))

print("\nPreorder:")
preorder(root)

print("\nInorder:")
inorder(root)

print("\nPostorder:")
postorder(root) 


    
