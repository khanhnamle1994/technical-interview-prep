def mirror_tree(root):
    if root == None: return

    # Do a post-order traversal of the binary tree
    if root.left != None:
        mirror_tree(root.left)

    if root.right != None:
        mirror_tree(root.right)

    # Swap the left and right nodes at the current level
    temp = root.left
    root.left = root.right
    root.right = temp
