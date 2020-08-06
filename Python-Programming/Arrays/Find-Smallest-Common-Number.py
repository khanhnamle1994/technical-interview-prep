def find_least_common_number(a, b, c):

    # Initialize three iterators
    i =  j = k = 0

    # Traverse the three arrays
    while i < len(a) and j < len(b) and k < len(c):

        # Find the smallest common number
        if a[i] == b[j] and b[j] == c[k]:
            return a[i]

        # Let's increment the iterator for the smallest value
        if a[i] <= b[j] and a[i] <= c[k]:
            i += 1
        elif b[j] <= a[i] and b[j] <= c[k]:
            j += 1
        elif c[k] <= a[i] and c[k] <= b[j]:
            k += 1

    return -1

# Driver code
a = [6, 7, 10, 25, 30, 63, 64]
b = [-1, 4, 5, 6, 7, 8, 50]
c = [1, 6, 10, 14]
print(find_least_common_number(a, b, c))
