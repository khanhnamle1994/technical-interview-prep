def length_of_longest_subarray_with_ones(arr, k):
    window_start, max_length, max_ones_count = 0, 0, 0

    # Try to extend the range [window_start, window_end]
    for window_end in range(len(str)):
        if arr[window_end] == 1:
            max_ones_count += 1

        '''
        Current window size is from window_start to window_end.
        Overall we have a maximum of 1s repeating 'max_ones_count' times, this means we can have a window with 'max_ones_count' 1s and the remaining are 0s which we should replace with 1s.
        If the remaining 1s are more than 'k', it is the time to shrink the window as we are not allowed to replace more than 'k' 0s.
        '''
        if (window_end - window_start + 1 - max_rones_count) > k:
            if arr[window_start] == 1:
                max_ones_count -= 1
            window_start += 1

        max_length = max(max_length, window_end - window_start + 1)
    return max_length
