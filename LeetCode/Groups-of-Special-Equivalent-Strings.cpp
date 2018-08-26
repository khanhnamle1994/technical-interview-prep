// You are given an array A of strings.
// Two strings S and T are special-equivalent if after any number of moves, S == T.
// A move consists of choosing two indices i and j with i % 2 == j % 2, and swapping S[i] with S[j].
// Now, a group of special-equivalent strings from A is a non-empty subset S of A such that any string not in S is not special-equivalent with any string in S.
// Return the number of groups of special-equivalent strings from A.

/* Example 1:
Input: ["a","b","c","a","c","c"]
Output: 3
Explanation: 3 groups ["a","a"], ["b"], ["c","c","c"]

Example 2:
Input: ["aa","bb","ab","ba"]
Output: 4
Explanation: 4 groups ["aa"], ["bb"], ["ab"], ["ba"]

Example 3:
Input: ["abc","acb","bac","bca","cab","cba"]
Output: 3
Explanation: 3 groups ["abc","cba"], ["acb","bca"], ["bac","cab"]

Example 4:
Input: ["abcd","cdab","adcb","cbad"]
Output: 1
Explanation: 1 group ["abcd","cdab","adcb","cbad"] */

int numSpecialEquivGroups(vector<string>& A) {
  set<pair<string,string>> s;
  for (const auto& w : A) {
      pair<string,string> p;
      for (int i = 0; i < w.size (); ++i) {
          if (i % 2) p.first  += w[i];
          else       p.second += w[i];
      }
      sort (p.first.begin  (), p.first.end ());
      sort (p.second.begin (), p.second.end ());
      s.insert (p);
  }
  return s.size ();
}

/* General Idea:
1 - Split strings in two to substrings, 1 with even indexed characters, and 1 with odd
2 - Sort the two substrings (We do this because if you can swap on string with another, when sorted they will equal each other because they must have the same characters)
3 - Insert your pair of strings into set, this will keep track of the unique "groups"
4 - Return the size of your set */
