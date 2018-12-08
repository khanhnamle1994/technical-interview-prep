/* Starting with a positive integer N, we reorder the digits in any order (including the original order) such that the leading digit is not zero.

Return true if and only if we can do this in a way such that the resulting number is a power of 2.

Example 1:
Input: 1
Output: true

Example 2:
Input: 10
Output: false

Example 3:
Input: 16
Output: true

Example 4:
Input: 24
Output: false

Example 5:
Input: 46
Output: true */

long counter(int N) {
  long res = 0;
  for (; N; N /= 10) res += pow(10, N % 10);
  return res;
}

bool reorderedPowerOf2(int N) {
  long c = counter(N);
  for (int i = 0; i < 32; i++)
      if (counter(1 << i) == c) return true;
  return false;
}
