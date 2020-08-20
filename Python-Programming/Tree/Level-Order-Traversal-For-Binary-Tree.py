def level_order_traversal(root):
    if root == None: return
    current_queue = deque()
    current_queue.append(root)
    current_queue.append(None)

    while len(current_queue) != 0:
        temp = current_queue.popleft()
        print(str(temp.data), end = " ")

        if temp.left != None:
            current_queue.append(temp.left)
        if temp.right != None:
            current_queue.append(temp.right)
        if current_queue[0] == None:
            print()
            current_queue.popleft()
            if len(current_queue) != 0:
                current_queue.append(None)

    print()
