def inorder_iterative(root):
    if root == None: return

    stack = deque()  # A stack is used to track the nodes
    count = 0

    while (len(stack) != 0 or root != None):
        if root != None:
            stack.append(root)
            root = root.left
            continue

        print(str(stack[-1].data), end = " ")
        root = stack[-1].right
        stack.pop()
