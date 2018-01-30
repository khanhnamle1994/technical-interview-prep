// Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
// Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
// The order of output does not matter.

/* Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab". */

bool isEqual(vector<int> a, vector<int> b) {
    if(a.size() != b.size())
        return false;

    for(int i=0; i<a.size(); i++) {
        if(a[i]!=b[i])
            return false;
    }
    return true;
}

vector<int> findAnagrams(string s, string p) {
  vector<int> retVec;
  if(s.length()<p.length() || s.length()==0)
      return retVec;

  vector<int> pFreq(26, 0), sFreq(26,0);
  for(int i=0; i<p.length(); i++) {
      pFreq[p[i]-'a']++;
      sFreq[s[i]-'a']++;
  }

  for(int i=0; i<=s.length()-p.length(); i++) {
      if(isEqual(pFreq, sFreq)) {
          retVec.push_back(i);
      }
      if(i == s.length()-p.length())
        break;
      sFreq[s[i]-'a']--;
      sFreq[s[i + p.length()]-'a']++;
  }

  return retVec;
}
