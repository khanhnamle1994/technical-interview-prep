from collections import deque

def find_max_sliding_window(arr, window_size):
    if len(arr) == 0: return
    if window_size > len(arr): return

    window = deque()
    result = []

    # Find out max for first window
    for i in range(0, window_size):
        while window and arr[i] >= arr[window[-1]]:
            window.pop()
        window.append(i)

    result.append(arr[window[0]])

    for i in range(window_size, len(arr)):
        # remove all numbers smaller than current number from the tail of list
        while window and arr[i] >= arr[window[-1]]:
            window.pop()

        # remove first number if it doesn't fall in the window anymore
        if window and (window[0] <= i - window_size):
            window.popleft()

        window.append(i)
        result.append(arr[window[0]])

    return result

# Driver Code
arr = [-4, 2, -5, 3, 6]
window_size = 3
print(find_max_sliding_window(arr, window_size)-)
