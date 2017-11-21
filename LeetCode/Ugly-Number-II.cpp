// Write a program to find the n-th ugly number.
// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
// For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
// Note that 1 is typically treated as an ugly number, and n does not exceed 1690.

int nthUglyNumber(int n) {
  if(n <= 0) return false; // get rid of corner cases
  if(n == 1) return true; // base case

  int t2 = 0, t3 = 0, t5 = 0; //pointers for 2, 3, 5
  vector<int> k(n);
  k[0] = 1;

  for(int i  = 1; i < n ; i ++)
  {
      k[i] = min(k[t2] * 2,min(k[t3] * 3,k[t5] * 5));
      if(k[i] == k[t2] * 2) t2++;
      if(k[i] == k[t3] * 3) t3++;
      if(k[i] == k[t5] * 5) t5++;
  }
  return k[n-1];
}

// Dynamic Programming Solution
// We have an array k of first n ugly number. We only know, at the beginning, the first one, which is 1. Then
// k[1] = min( k[0]x2, k[0]x3, k[0]x5). The answer is k[0]x2. So we move 2's pointer to 1. Then we test:
// k[2] = min( k[1]x2, k[0]x3, k[0]x5). And so on. Be careful about the cases such as 6, in which we need to
// forward both pointers of 2 and 3.
// x here is multiplication.
