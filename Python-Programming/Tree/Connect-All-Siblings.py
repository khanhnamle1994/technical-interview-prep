def populate_sibling_pointers(root):
    if root == None: return

    current = root
    last = root

    while current != None:
        if current.left != None:
            last.next = current.left
            last = current.left

        if current.right != None:
            last.next = current.right
            last = current.right

        last.next = None
        current = current.next
