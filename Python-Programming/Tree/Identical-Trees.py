def are_identical(root1, root2):
    # Empty Trees
    if root1 == None and root2 == None:
        return True
    if root1 != None and root2 != None:
        # Both roots are the same
        # Both left subtrees are the same
        # Both right subtrees are the same
        return (root1.data == root2.data and
        are_identical(root1.left, root2.left) and
        are_identical(root1.right, root2.right))

    return False
