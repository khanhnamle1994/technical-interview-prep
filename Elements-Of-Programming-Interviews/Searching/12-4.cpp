// Write a program that takes a non-negative integer and returns the largest integer whose square is less than or equal to the given integer

/* Solution:
We can maintain an interval consisting of values whose squares are unclassified with respect to k. We initialize the interval to [0,k].
We compare the square of m = [(l + r) / 2] with k, and use the elimination rule to update the interval. If m^2 <= k, we know all integers
less than or equal to m have a square less than or equal to k. Therefore, we update the interval to [m + 1, r]. If m^2 > k, we know all
numbers greater than or equal to m have a square greater than k, so we update the candidate interval to [l, m - 1]. The algorithm terminates
when the interval is empty, in which case every number less than l has a square less than or equal to k and l's square is greater than k,
so the result is l - 1. */

int SquareRoot(int k) {
  int left = 0, right = k;
  // Candidate interval [left, right] where everything before left has square <= k, and everything after right has square > k
  while(left < right) {
    long mid = left + ((right - left) / 2);
    long mid_squared = mid * mid;
    if(mid_squared <= k) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return left - 1;
}

// The time complexity is that of binary search over the interval [0, k] - O(log k)
