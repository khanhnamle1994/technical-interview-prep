prev = -1

def is_binary_search_tree(root):
    prev = -1
    return helper(root)

def helper(root):
    global prev
    if root == None:
        return True
    if helper(root.left) == False:
        return False
    if prev > root.data and prev != -1:
        return False
    prev = root.data
    if helper(root.right) == False:
        return False
    return True
