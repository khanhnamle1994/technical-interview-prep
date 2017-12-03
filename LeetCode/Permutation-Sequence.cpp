// The set [1,2,3,…,n] contains a total of n! unique permutations.
/* By listing and labeling all of the permutations in order, We get the following sequence (ie, for n = 3):
"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence. */

string getPermutation(int n, int k) {
  int i,j,f = 1;
  // left part of s is partially formed permutation, right part is the leftover chars.
  string s(n,'0');
  for(i = 1; i <= n; i++){
      f *= i;
      s[i - 1] += i; // make s become 1234...n
  }
  for(i = 0, k--; i < n; i++){
      f /= n - i;
      j = i + k/f; // calculate index of char to put at s[i]
      char c = s[j];
      // remove c by shifting to cover up (adjust the right part).
      for(; j>i; j--)
          s[j] = s[j - 1];
      k %= f;
      s[i] = c;
  }
  return s;
}
