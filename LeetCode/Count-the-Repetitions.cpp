// Define S = [s,n] as the string S which consists of n connected strings s. For example, ["abc", 3] ="abcabcabc".

// On the other hand, we define that string s1 can be obtained from string s2 if we can remove some characters from s2 such that it becomes s1. For example, “abc” can be obtained from “abdbec” based on our definition, but it can not be obtained from “acbbe”.

// You are given two non-empty strings s1 and s2 (each at most 100 characters long) and two integers 0 ≤ n1 ≤ 106 and 1 ≤ n2 ≤ 106. Now consider the strings S1 and S2, where S1=[s1,n1] and S2=[s2,n2]. Find the maximum integer M such that [S2,M] can be obtained from S1.

/* Example:

Input:
s1="acb", n1=4
s2="ab", n2=2

Return:
2 */

int getMaxRepetitions(string s1, int n1, string s2, int n2) {
  for(auto c : s2) {
      // preventive checkings, it could be O(n), but who cares.
      if (s1.find(c) == string::npos) return 0;
  }
  int p1 = 0, p2 = 0, mark = 0;
  while(p1 < s1.length() * n1) {
      char c = s2[p2 % s2.length()];
      while(s1[p1 % s1.length()] != c && p1 < s1.length() * n1) p1 ++;
      p2++;
      p1++;
      // optimization part below
      if (p2 % s2.length() == 0) {
          if (p2 == s2.length()) {
              mark = p1; // mark the position in s1, when the first s2 ends
          } else if (p1 % s1.length() == mark % s1.length()) {
              // s1 reaches the same position, which means the repeating cycle found.
              //Then we can leap forward.
              int round = (s1.length() * n1 - p1) / (p1 - mark);
              p1 += round * (p1 - mark);
              p2 += round * (p2 - s2.length());
          }
      }
  }
  return p2 / s2.length() / n2;
}
