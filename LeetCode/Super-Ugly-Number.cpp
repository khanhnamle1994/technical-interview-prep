// Write a program to find the nth super ugly number.
// Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k.
// For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given
// primes = [2, 7, 13, 19] of size 4.

int nthSuperUglyNumber(int n, vector<int>& primes) {
  vector<int> index(primes.size(), 0), ugly(n, INT_MAX);
  ugly[0] = 1;

  for(int i = 1; i < n; i++){
      for(int j = 0; j < primes.size(); j++) {
        ugly[i] = min(ugly[i],ugly[index[j]] * primes[j]);
      }
      for(int j=0; j<primes.size(); j++) {
        index[j] += (ugly[i] == ugly[index[j]] * primes[j]);
      }
  }
  return ugly[n - 1];
}
