def connect_next_level(head):
    current = head
    next_level_head = None
    prev = None # keep track of the previously connected nodes

    while current != None:
        # If the current node has both the left and right child, connect them with each other and with the previously connected nodes
        if current.left != None and current.right != None:
            if next_level_head == None:
                next_level_head = current.left
            current.left.next = current.right
            if prev != None:
                prev.next = current.left
            prev = current.right

        # If the current node has only left child, connect it with previously connected nodes
        elif current.left != None:
            if next_level_head == None:
                next_level_head = current.left
            if prev != None:
                prev.next = current.left
            prev = current.left

        # If the current node has only right child, connect it with previously connected nodes
        elif current.right != None:
            if next_level_head == None:
                next_level_head = current.right
            if prev != None:
                prev.next = current.right
            prev = current.right

        current = current.next

    if prev != None:
        prev.next = None

    return next_level_head

def populate_sibling_pointers(root):
    if root == None: return
    root.next = None
    while root != None:
        root = connect_next_level(root)
