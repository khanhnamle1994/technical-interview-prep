/* Find the largest palindrome made from the product of two n-digit numbers.

Since the result could be very large, you should return the largest palindrome mod 1337.

Example:
Input: 2
Output: 987
Explanation: 99 x 91 = 9009, 9009 % 1337 = 987 */

long buildPalindrome(int n) {
  string s = to_string(n);
  reverse(s.begin(), s.end());
  return stol(to_string(n) + s);
}

int largestPalindrome(int n) {
  if (n == 1) return 9;
  int upper = pow(10, n) - 1;
  int lower = pow(10, n-1);
  for (int i = upper; i >= lower; i--) {
      long cand = buildPalindrome(i);
      for (long j = upper; j*j >= cand; j--) {
          if (cand % j == 0 && cand / j <= upper) {
              return cand % 1337;
          }
      }
  }
  return -1;
}
