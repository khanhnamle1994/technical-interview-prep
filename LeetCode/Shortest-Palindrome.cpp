// Given a string s, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

/* Example 1:
Input: "aacecaaa"
Output: "aaacecaaa"

Example 2:
Input: "abcd"
Output: "dcbabcd" */

// Consturct failure function of s
inline vector<int> funcFailure(string &s){
  size_t len = s.size();
  vector<int> pattern(len);
  pattern[0] = -1;
  pattern[1] = 0;
  for(size_t i = 2; i < len; i++){
      int p = pattern[i-1];
      while(p >= 0 && s[p] != s[i-1]){
          p = pattern[p];
      }
      pattern[i] = p + 1;
  }
  return pattern;
}

string shortestPalindrome(string s) {
  int len = s.size();
  if(len <= 1) return s;
  string rev(s.rbegin(), s.rend());
  vector<int> pattern = funcFailure(s);
  int i = 0, j = 0;
  while(true){
      // Just do normal string search in reversed string, while orginal string is the target.
      while(i < len && j < len && rev[i] == s[j]) i++, j++;
      if(i == len || j == len) break;
      if(j) j = pattern[j];
      else i++;
  }
  // j is the length longest palindrome prefix, and is also the suffix of rev, so we need append the part of original string truncated from j.
  return rev + s.substr(j);
}
