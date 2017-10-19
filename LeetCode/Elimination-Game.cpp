// There is a list of sorted integers from 1 to n. Starting from left to right, remove the first number and every other number afterward
// until you reach the end of the list.

// Repeat the previous step again, but this time from right to left, remove the right most number and every other number from the remaining
// numbers.

// We keep repeating the steps again, alternating left to right and right to left, until a single number remains.

// Find the last number that remains starting with a list of length n.

/* Example:

Input:
n = 9,
1 2 3 4 5 6 7 8 9
2 4 6 8
2 6
6

Output:
6
*/

int lastRemaining(int n) {
  return n == 1 ? 1 : 2 * (1 + n / 2 - lastRemaining(n / 2));
}

// After first elimination, all the numbers left are even numbers.
// Divide by 2, we get a continuous new sequence from 1 to n / 2.
// For this sequence we start from right to left as the first elimination.
// Then the original result should be two times the mirroring result of lastRemaining(n / 2).
