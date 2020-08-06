def binary_search_rotated(arr, key):
    # iterative solution
    # assuming all the keys are unique
    start = 0
    end = len(arr) - 1
    if start > end: return -1

    while start <= end:
        mid = start + (end - start) // 2

        if arr[mid] == key:
            return mid

        if (arr[start] <= arr[mid] and key <= arr[mid] and key >= arr[start]):
            end = mid - 1
        elif (arr[mid] <= arr[end] and key >= arr[mid] and key <= arr[end]):
            start = mid + 1
        elif arr[end] <= arr[mid]:
            start = mid + 1
        elif arr[start] >= arr[mid]:
            end = mid - 1
    return - 1

# Driver Code
arr = [176, 188, 199, 200, 210, 222, 1, 10, 20, 47, 59, 63, 75, 88, 99, 107, 120, 133, 155, 162]
key = 200
print(binary_search_rotated(arr, key))
