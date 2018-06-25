/* Given a positive integer n, return the number of all possible attendance records with length n, which will be regarded as rewardable. The answer may be very large, return it after mod 10^9 + 7.

A student attendance record is a string that only contains the following three characters:
1 - 'A' : Absent.
2 - 'L' : Late.
3 - 'P' : Present.

A record is regarded as rewardable if it doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

Example 1:

Input: n = 2
Output: 8
Explanation:
There are 8 records with length 2 will be regarded as rewardable:
"PP" , "AP", "PA", "LP", "PL", "AL", "LA", "LL"
Only "AA" won't be regarded as rewardable owing to more than one absent times.  */

int checkRecord(int n) {
  int m = 1000000007;
  int *A = new int [n];
  int *P = new int [n];
  int *L = new int [n];

  P[0] = 1;
  L[0] = 1;
  L[1] = 3;
  A[0] = 1;
  A[1] = 2;
  A[2] = 4;

  if(n == 1) return 3;

  for(int i = 1; i < n; i++)
  {
      A[i - 1] %= m;
      P[i - 1] %= m;
      L[i - 1] %= m;

      P[i] = ((A[i - 1] + P[i - 1]) % m + L[i - 1]) % m;

      if(i > 1) L[i] = ((A[i - 1] + P[i - 1]) % m + (A[i - 2] + P[i - 2]) % m) % m;

      if(i > 2) A[i] = ((A[i - 1] + A[i - 2]) % m + A[i - 3]) % m;
  }

  return ((A[n - 1] % m + P[n - 1] % m) % m + L[n - 1] % m) % m;
}
