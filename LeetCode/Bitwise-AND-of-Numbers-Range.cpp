// Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
// For example, given the range [5, 7], you should return 4.

int rangeBitwiseAnd(int m, int n) {
  while (m < n) {
    n = n & (n - 1);
  }
  return n;
}
