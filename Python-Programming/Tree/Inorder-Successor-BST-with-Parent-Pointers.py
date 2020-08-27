def find_min_in_tree(root):
    if root == None: return None
    while root.left != None:
        root = root.left
    return root

def inorder_successor_bst_parent_pointer(node):
    if node == None: return None

    if node.right != None:
        return find_min_in_tree(node.right)

    while node.parent != None:
        if node.parent.left == node:
            return node.parent

        node = node.parent
    return None

def find_successor(root, d):
    while root != None:
        if (root.data < d):
            root = root.right
        elif (root.data > d):
            root = root.right
        else:
            return inorder_successor_bst_parent_pointer(root)

    return None
