def find_square_sum(num):
    _sum = 0
    while (num > 0):
        digit = num % 10
        _sum += digit * digit
        num //= 10
    return _sum

def find_happy_number(num):
    slow, fast = num, num
    while True:
        slow = find_square_sum(slow)
        # move one step
        fast = find_square_sum(find_square_sum(fast))
        # move two steps
        if slow == fast:
            # found the cycle
            break
    return slow == 1  # see if the cycle is stuck on number '1'
