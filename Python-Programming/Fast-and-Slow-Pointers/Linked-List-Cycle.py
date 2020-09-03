class Node:
    def __init__(self, value, next=None):
        self.value = value
        self.next = next

    def has_cycle(head):
        slow, fast = head, head
        while fast is not None and fast.next is not None:
            fast = fast.next.next
            slow = slow.next
            if slow == fast:
                return True  # found the cycle

        return False
