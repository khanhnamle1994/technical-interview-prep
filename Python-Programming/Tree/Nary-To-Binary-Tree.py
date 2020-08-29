def convert_n_ary_to_binary(node):
    return convert_n_ary_to_binary_rec(node, 1)

def convert_n_ary_to_binary_rec(root, isLeft):
    if root == None: return

    btnode = BinaryTreeNode(root.data)
    lastnode = btnode

    for child in root.children:
        if isLeft == 1:
            lastnode.left = convert_n_ary_to_binary_rec(child, 0)
            lastnode = lastnode.left
        else:
            lastnode.right = convert_n_ary_to_binary_rec(child, 1)
            lastnode = lastnode.right

    return btnode

def convert_binary_to_n_ary(node):
    return convert_binary_to_n_ary_rec(node, 1)

def convert_binary_to_n_ary_rec(node, isLeft):
    if node == None: return

    nnode = TreeNode(node.data)
    temp = node

    if isLeft == 1:
        while(temp.left != None):
            child = convert_binary_to_n_ary_rec(temp.left, 0)
            nnode.children.append(child)
            temp = temp.left
    else:
        while(temp.right != None):
            child = convert_binary_to_n_ary_rec(temp.right, 1)
            nnode.children.append(child)
            temp = temp.right
    return nnode
