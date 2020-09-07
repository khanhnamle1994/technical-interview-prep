def non_repeat_substring(str):
    window_start = 0
    max_length = 0
    char_index_map = {}

    # In this loop, we extend the range [window_start, window_end]
    for window_end in range(len(str)):
        right_char = str[window_end]

        # If the map already contains the 'right_char', shrink the window from the beginning so that we have only one occurrence of 'right_char'
        if right_char in char_index_map:
            # In the current window, we'll not have any 'right_char' after its previous index and if 'window_start' is already ahead of the last index of the 'right_char', we'll keep 'window_start'
            window_start = max(window_start, char_index_map[right_char] + 1)

        # Insert the 'right_char' into the map
        char_index_map[str[window_end]] = window_end
        # remember the maximum length so far
        max_length = max(max_length, window_end - window_start + 1)
    return max_length
