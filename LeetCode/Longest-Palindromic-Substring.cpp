// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
/* Example:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example:
Input: "cbbd"
Output: "bb" */

#include <iostream>
#include <string.h>
using namespace std;

string longestPalindrome(string s) {
  int n = s.length();
  if (n == 0) { return ""; }

  bool table[1000][1000] = {false};

  int maxst = 0;
  int maxlen = 1;

  for(int i = 0; i < n; i++) {
    table[i][i] = true;
    maxst = i;
    maxlen = 1;
  }

  for(int i = 0; i < n - 1; i++) {
    if(s[i] == s[i + 1]) {
      table[i][i + 1] = true;
      maxst = i;
      maxlen = 2;
    }
  }

  for(int len = 3; len <= n; len++) {
    for(int i = 0; i < n - len + 1; i++) {
      int j = i + len - 1;
      if(s[i] == s[j] && table[i + 1][j - 1]) {
        table[i][j] = true;
        maxst = i;
        maxlen = len;
      }
    }
  }
  return s.substr(maxst, maxlen);
}

int main() {
  string s1 = "cbbd";
  string s2 = longestPalindrome(s1);
  for(int i = 0; i < s2.length(); i++) {
    cout << s2[i];
  }
  return 0;
}
