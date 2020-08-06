def move_zeros_to_left(A):
    if len(A) < 1: return

    lengthA = len(A)
    write_index = lengthA - 1
    read_index = lengthA - 1

    while(read_index >= 0):
        if A[read_index] != 0:
            A[write_index] = A[read_index]
            write_index -= 1

        read_index -= 1

    while (write_index >= 0):
        A[write_index] = 0
        write_index -= 1

    return A


# Driver Code
A = [1, 0, 10, 20, 0, 59, 0, 63, 88]
print(move_zeros_to_left(A))
