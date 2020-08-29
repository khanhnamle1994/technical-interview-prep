def find_nth_highest_in_bst_with_counts(node, n):

    if node == None: return None
    left_count = 0

    if node.left != None:
        left_count = node.left.count

    k = node.count - left_count

    if k == n:
        return node
    elif k > n:
        return find_nth_highest_in_bst_with_counts(node.right, n)
    else:
        return find_nth_highest_in_bst_with_counts(node.left, n - k)
