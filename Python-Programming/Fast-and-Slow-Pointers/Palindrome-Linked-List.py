class Node:
    def __init__(self, value, next=None):
        self.value = value
        self.next = next

def is_palindromic_linked_list(head):
    if head is None or head.next is None:
        return True

    # find the middle of the LinkedList
    slow, fast = head, head
    while (fast is not None and fast.next is not None):
        slow = slow.next
        fast = fast.next.next

    # reverse the second half
    head_second_half = reverse(slow)

    # store the head of reversed part to revert back later
    copy_head_second_half = head_second_half

    # compare the first and second half
    while (head is not None and head_second_half is not None):
        if head.value != head_second_half.value:
            break # not a palindrome
        head = head.next
        head_second_half = head_second_half.next

    # revert the reverse of the second half
    reverse(copy_head_second_half)

    # if both halves match
    if head is None or head_second_half is None:
        return True

    return False

def reverse(head):
    prev = None

    while (head is not None):
        next = head.next
        head.next = prev
        prev = head
        head = next

    return prev
