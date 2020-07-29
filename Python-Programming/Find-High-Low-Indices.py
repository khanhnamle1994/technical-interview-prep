def find_low_index(arr, key):
    low = 0
    high = len(arr) - 1
    mid = int(high / 2)

    # Binary Search
    while low <= high:
        mid_elem = arr[mid]
        if mid_elem < key:
            low = mid + 1
        else:
            high = mid - 1

        mid = low + int((high - low) / 2)

    if low < len(arr) and arr[low] == key:
        return low

    return -1

def find_high_index(arr, key):
    low = 0
    high = len(arr) - 1
    mid = int(high / 2)

    # Binary Search
    while low <= high:
        mid_elem = arr[mid]
        if mid_elem <= key:
            low = mid + 1
        else:
            high = mid - 1

        mid = low + int((high - low) / 2)

    if high < len(arr) and arr[high] == key:
        return high

    return -1

# Driver Code
arr = [1, 2, 5, 5, 5, 5, 5, 5, 5, 5, 20]
key = 5
print(find_low_index(arr, key), find_high_index(arr, key))
