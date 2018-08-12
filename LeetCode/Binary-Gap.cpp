// Given a positive integer N, find and return the longest distance between two consecutive 1's in the binary representation of N.

// If there aren't two consecutive 1's, return 0.

/* Example 1:

Input: 22
Output: 2
Explanation:
22 in binary is 0b10110.
In the binary representation of 22, there are three ones, and two consecutive pairs of 1's.
The first consecutive pair of 1's have distance 2.
The second consecutive pair of 1's have distance 1.
The answer is the largest of these two distances, which is 2.

Example 2:

Input: 5
Output: 2
Explanation:
5 in binary is 0b101.

Example 3:

Input: 6
Output: 1
Explanation:
6 in binary is 0b110.

Example 4:

Input: 8
Output: 0
Explanation:
8 in binary is 0b1000.
There aren't any consecutive pairs of 1's in the binary representation of 8, so we return 0. */

int binaryGap(int N) {
  int res = 0;
  for (int d = -32; N; N /= 2, d++)
      if (N % 2) res = max(res, d), d = 0;
  return res;
}
