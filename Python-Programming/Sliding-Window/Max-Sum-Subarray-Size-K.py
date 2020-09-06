def max_sub_array_of_size_k(k, arr):
    max_sum, window_sum = 0, 0
    window_start = 0

    for window_end in range(len(arr)):
        # add the next element
        window_sum += arr[window_end]
        # slide the window, we don't need to slide if we have not hit the required window size of 'k'
        if window_end >= k - 1:
            max_sum = max(max_sum, window_sum)
            # subtract the element going out
            window_sum -= arr[window_start]
            window_start += 1 # slide the window ahead

    return max_sum
