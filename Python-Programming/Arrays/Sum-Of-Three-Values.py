def find_sum_of_two(A, val, start_index):
    i = start_index
    j = len(A) - 1

    while i < j:
        s = A[i] + A[j]
        if s == val:
            return True

        if s < val:
            i += 1
        else:
            j -= 1

    return False

def find_sum_of_three(arr, required_sum):
    arr.sort()
    for i in range(0, len(arr) - 2):
        remaining_sum = required_sum - arr[i]
        if find_sum_of_two(arr, remaining_sum, i + 1):
            return True
    return False

# Driver Code
arr = [3, 7, 1, 2, 8, 4, 5]
print(find_sum_of_three(arr, 20))
print(find_sum_of_three(arr, 21))
