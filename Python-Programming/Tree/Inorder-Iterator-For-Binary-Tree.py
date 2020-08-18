class InorderIterator:
    def __init__(self, root):
        self.stack = []
        while root != None:
            self.stack.append(root)
            root = root.left

    # Check whether the stack is empty or not
    def hasNext(self):
        if not self.stack:
            return False
        else:
            return True

    # Return the next element in inorder traversal
    def getNext(self):
        # Empty stack
        if not self.stack:
            return None
        # Return the top node from the stack
        r_val = self.stack[-1]
        del self.stack[-1]

        # temp stores the right child of the top node
        temp = r_val.right
        # If temp is non-null
        while temp != None:
            # Push all the nodes from temp to temp's leftmost node onto the stack
            self.stack.append(temp)
            temp = temp.left
        return r_val

    def inorder_using_iterator(root):
        iter = InorderIterator(root)
        while iter.hasNext():
            ptr = iter.getNext()
            print(ptr.data, end = ", ")
        print()
