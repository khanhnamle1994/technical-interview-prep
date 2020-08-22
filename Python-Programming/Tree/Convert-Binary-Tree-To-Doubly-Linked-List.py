# Fuse two sorted linked lists
def concatenate_lists(head1, head2):
    if head1 == None:
        return head2
    if head2 == None:
        return head1

    # Use left for previous and right for next
    tail1 = head1.left
    tail2 = head2.left

    tail1.right = head2
    head2.left = tail1
    head1.left = tail2
    tail2.right = head1

    return head1

def convert_to_linked_list(root):
    if root == None:
        return None

    # Recursive calls to left and right subtrees
    list1 = convert_to_linked_list(root.left)
    list2 = convert_to_linked_list(root.right)

    root.left = root.right = root
    # Fuse output of left subtree with root to get intermediate result
    intermediate_result = concatenate_lists(list1, root)

    # Fuse intermediate result with output from the right subtree to get final result
    final_result = concatenate_lists(intermediate_result, list2)

    return final_result
