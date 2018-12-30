/* Given a list of words, we may encode it by writing a reference string S and a list of indexes A.

For example, if the list of words is ["time", "me", "bell"], we can write it as S = "time#bell#" and indexes = [0, 2, 5].

Then for each index, we will recover the word by reading from the reference string from that index until we reach a "#" character.

What is the length of the shortest reference string S possible that encodes the given words?

Example:
Input: words = ["time", "me", "bell"]
Output: 10
Explanation: S = "time#bell#" and indexes = [0, 2, 5]. */

int minimumLengthEncoding(vector<string>& words) {
  unordered_set<string> s(words.begin(), words.end());
  for (string w : s)
      for (int i = 1; i < w.size(); ++i)
          s.erase(w.substr(i));
  int res = 0;
  for (string w : s) res += w.size() + 1;
  return res;
}
