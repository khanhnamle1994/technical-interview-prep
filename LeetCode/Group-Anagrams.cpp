// Given an array of strings, group anagrams together.

/* For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], return:
[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
*/

vector< vector<string> > groupAnagrams(vector<string>& strs) {
  unordered_map<string, multiset<string> > mp;
  for (string s : strs) {
    string t = strSort(s);
    mp[t].insert(s);
  }

  vector< vector<string> > anagrams;
  for (auto m : mp) {
    vector<string> anagram(m.second.begin(), m.second.end());
    anagrams.push_back(anagram);
  }
  return anagrams;
}

string strSort(string& s) {
  int count[26] = {0}, n = s.length();
  for (int i = 0; i < n; i++) {
    count[s[i] - 'a']++;
  }
  int p = 0;
  string t(n, 'a');
  for (int j = 0; j < 26; j++) {
    for (int i = 0; i < count[j]; i++) {
      t[p++] += j;
    }
  }
  return t;
}
