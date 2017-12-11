// Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.
/* Example:
Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100,
excluding [11,22,33,44,55,66,77,88,99]) */

int permutation(int n, int r) {
  if (r == 0) {
    return 1;
  } else {
    return n * permutation(n - 1, r - 1);
  }
}

int countNumbersWithUniqueDigits(int n) {
  int sum = 1;
  if (n > 0) {
    int end = (n > 10) ? 10 : n;
    for (int i = 0; i < end; i++) {
      sum += 9 * permutation(9, i);
    }
  }
  return sum;
}
