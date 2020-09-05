class Node:
    def __init__(self, value, next=None):
        self.value = value
        self.next = next

def reorder(head):
    if head is None or head.next is None:
        return True

    # find the middle of the LinkedList
    slow, fast = head, head
    while (fast is not None and fast.next is not None):
        slow = slow.next
        fast = fast.next.next
    # slow is now pointing to the middle node

    # reverse the second half
    head_second_half = reverse(slow)
    head_first_half = head

    # rearrange to produce the LinkedList in the required order
    while head_first_half is not None and head_second_half is not None:
        temp = head_first_half.next
        head_first_half.next = head_second_half
        head_first_half = temp

        temp = head_second_half.next
        head_second_half.next = head_first_half
        head_second_half = temp

    # set the next of the last node to 'None'
    if head_first_half is not None:
        head_first_half.next = None

def reverse(head):
    prev = None

    while (head is not None):
        next = head.next
        head.next = prev
        prev = head
        head = next

    return prev
