// Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
// If the last word does not exist, return 0.
// Note: A word is defined as a character sequence consists of non-space characters only.

// For example, given s = "Hello World", return 5.

/* Analysis:
- Simple problem, but be careful with the special cases. Such as:  "  " , "  day" ,"day   ",etc.
- The basic idea is search from the end to the start, if the current letter is A-Z a-z, count the word, until find the space or meet the
start, return the length. */

class Solution {
public:
  int lengthOfLastWord(string s) {
    int len = strlen(s);
    if (len == 0) { return 0; }
    int res = 0;
    for (int i = len - 1; i >= 0; i--) {
      if (s[i] != ' ') {
        res++;
      } else {
        if (res > 0) {
          return res;
        }
      }
      return res;
    }
  }
}
