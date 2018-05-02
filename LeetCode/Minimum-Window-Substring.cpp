// Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

/* Example:
Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC" */

string minWindow(string s, string t) {
  if (s.size() == 0 || t.size() == 0) return "";
  vector<int> remaining(128, 0);
  int required = t.size();
  for (int i = 0; i < required; i++) remaining[t[i]]++;

  // left is the start index of the min-length substring ever found
  int min = INT_MAX, start = 0, left = 0, i = 0;
  while(i <= s.size() && start < s.size()) {
      if(required) {
          if (i == s.size()) break;
          remaining[s[i]]--;
          if (remaining[s[i]] >= 0) required--;
          i++;
      } else {
          if (i - start < min) {
              min = i -start;
              left = start;
          }
          remaining[s[start]]++;
          if (remaining[s[start]] > 0) required++;
          start++;
      }
  }
  return min == INT_MAX? "" : s.substr(left, min);
}

/* Solution:
1 - Initialize a vector called remaining, which contains the needed matching numbers of each character in s.
2 - If there are still characters needed to be contained (increment i in this case), decrease the matching number of that character and check if it is still non-negative. If it is, then it is the character in t, so decrease the total required number required.
3 - If there is no more characters required (increment start in this case), record min and left if a smaller length is found. Recover the number of this character in the remaining and if it is a character in t increase required. */
