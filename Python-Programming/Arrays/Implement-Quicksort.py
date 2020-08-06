def partition(arr, low, high):
    pivot_value = arr[low]
    i, j = low, high

    while i < j:
        while i <= high and arr[i] <= pivot_value:
            i += 1
        while arr[j] > pivot_value:
            j -= 1
        if i < j:
            # Swap arr[i] and arr[j]
            arr[i], arr[j] = arr[j], arr[i]

    arr[low] = arr[j]
    arr[j] = pivot_value

    # Return the pivot index
    return j

def quick_sort_rec(a, l, h):
    if h > l:
        pivot_index = partition(a, l, h)
        quick_sort_rec(a, l, pivot_index - 1)
        quick_sort_rec(a, pivot_index + 1, h)

def quick_sort(a):
    quick_sort_rec(a, 0, len(a) - 1)
    return a

# Driver Code
a = [55, 23, 26, 2, 25]
print(quick_sort(a))
