def print_left_perimeter(root):
    while root != None:
        curr_val = root.data

        if root.left != None:
            root = root.left
        elif root.right != None:
            root = root.right
        else: # leaf node
            break
        print(str(curr_val) + " ")

def print_right_perimeter(root):
    r_values = [] # stack for right side values

    while root != None:
        curr_val = root.data

        if root.right != None:
            root = root.right
        elif root.left != None:
            root = root.leftt
        else: # leaf node
            break
        r_values.append(curr_val)

    while len(r_values) != 0:
        print(str(r_values.pop()) + " ")
