def delete_zero_sum_subtree_rec(root):
    if root == None: return 0

    sum_left = delete_zero_sum_subtree_rec(root.left)
    sum_right = delete_zero_sum_subtree_rec(root.right)

    if sum_left == 0: root.left = None
    if sum_right == 0: root.right = None

    return (root.data + sum_left + sum_right)

def delete_zero_sum_subtree(root):
    if root != None:
        sum = delete_zero_sum_subtree_rec(root)
        if sum == 0:
            root = None
