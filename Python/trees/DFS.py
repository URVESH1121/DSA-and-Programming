class Node:
    def __init__(self,data):
        self.data = data
        self.left = None
        self.right = None
        
    def insert(self,data):
        if self.data:
            if data<self.data:
                if self.left == None:
                    self.left = Node(data)
                else:
                    self.left.insert = data
            elif data>self.data:
                if self.right == None:
                    self.right = Node(data)
                else:
                    self.right.insert = data     
        else:
            self.data = data
            
    def PrintTree(self):
        if self.left:
            self.left.PrintTree()
        print(self.data)
        if self.right:
            self.right.PrintTree()
            
    def inorderTraversal(self,root):
        res = []
        if root:
            res = res + self.inorderTraversal(root.left)
            res.append(root.data)
            res = res + self.inorderTraversal(root.right)
        return res
    
    def PreorderTraversal(self,root):
        res = []
        if root:
            res.append(root.data)
            res = res + self.PreorderTraversal(root.left)
            res = res + self.PreorderTraversal(root.right)
        return res
    
    def PostorderTraversal(self,root):
        res = []
        if root:
            res = res + self.PostorderTraversal(root.left)
            res = res + self.PostorderTraversal(root.right)
            res.append(root.data)
        return res
    
root = Node(27)
root.insert(14)
root.insert(35)

# print(root.inorderTraversal(root))
# print(root.PreorderTraversal(root))
print(root.PostorderTraversal(root))