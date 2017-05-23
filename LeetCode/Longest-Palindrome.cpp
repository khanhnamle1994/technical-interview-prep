// Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built
// with those letters. This is case sensitive, for example "Aa" is not considered a palindrome here.

// I count how many letters appear an odd number of times. Because we can use all letters, except for each odd-count letter
// we must leave one, except one of them we can use.

class Solution {
public:
  int longestPalindrome(string s) {
      int odds = 0;
      for (char c='A'; c<='z'; c++)
          odds += count(s.begin(), s.end(), c) & 1;
          return s.size() - odds + (odds > 0);
  }
}
