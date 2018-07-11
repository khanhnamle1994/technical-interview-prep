// Let f(x) be the number of zeroes at the end of x!. (Recall that x! = 1 * 2 * 3 * ... * x, and by convention, 0! = 1.)

// For example, f(3) = 0 because 3! = 6 has no zeroes at the end, while f(11) = 2 because 11! = 39916800 has 2 zeroes at the end. Given K, find how many non-negative integers x have the property that f(x) = K.

/* Example 1:
Input: K = 0
Output: 5
Explanation: 0!, 1!, 2!, 3!, and 4! end with K = 0 zeroes.

Example 2:
Input: K = 5
Output: 0
Explanation: There is no x such that x! ends in K = 5 zeroes. */

int preimageSizeFZF(int K) {
  int sum[13]={1};
  for (int i=1; i<13; i++) sum[i]=sum[i-1]*5+1;
  for (int i=12; i>=0; i--) {
      if (K/sum[i]==5) return 0;
      K=K%sum[i];
  }
  return 5;
}
