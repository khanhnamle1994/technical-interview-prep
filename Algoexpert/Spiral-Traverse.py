"""
Write a function that takes in an n x m 2-D array and returns a 1-D array of all the array's elements in spiral order.

Spiral order starts at the top left corner of the two-dimensional array, goes to the right, and proceeds in a spiral pattern all the way until every element has been visited.
"""

"""
Hint 1: You can think of the spiral that you have to traverse as a set of rectangle perimeters that progressively get smaller.

Hint 2:
> Declare 4 variables: a starting row, a starting column, an ending row, and an ending column. These 4 variables represent the bounds of the first rectangle perimeter in the spiral that you have to traverse.
> Traverse that perimeter using those bounds, and then move the bounds inwards.
> End your algorithm once the starting row passes the ending row or the starting column passes the ending column.

Hint 3: This can be solved iteratively or recursively.

Optimal time and space complexity: O(n) - n is the number of elements in the 2-D array.
"""

def spiralTraverse(array):
    # Initialize result array
    result = []

    # Initialize the starting values for row and column
    start_row = 0
    start_col = 0
    # Initialize the ending values for row and column
    end_row = len(array)
    end_col = len(array[0])

    # Loop condition
    while (start_row < end_row and start_col < end_col):
        # Print the first row from the remaining rows
        for i in range(start_col, end_col):
            result.append(array[start_row][i])
        # Move bound inwards
        start_row += 1

        # Print the last column from the remaining columns
        for i in range(start_row, end_row):
            result.append(array[i][end_col - 1])
        # Move bound inwards
        end_col -= 1

        # Print the last row from the remaining rows
        for i in range(end_col - 1, start_col - 1, -1):
            if start_row == end_row:
                break
            result.append(array[end_row - 1][i])
        # Move bound inwards
        end_row -= 1

        # Print the first column from the remaining columns
        for i in range(end_row - 1, start_row - 1, -1):
            if start_col == end_col:
                break
            result.append(array[i][start_col])
        # Move bound inwards
        start_col += 1

    return result


# Driver Code
array = [
    [1, 2, 3, 4],
    [10, 11, 12, 5],
    [9, 8, 7, 6],
]

# Expected Output = [1, 2, ..., 15, 16]
print(spiralTraverse(array))
