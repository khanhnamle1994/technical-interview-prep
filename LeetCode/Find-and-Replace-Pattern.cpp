/* You have a list of words and a pattern, and you want to know which words in words matches the pattern.

A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

(Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.)

Return a list of the words in words that match the given pattern.

You may return the answer in any order.

Example 1:

Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}.
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation,
since a and b map to the same letter. */

vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
  vector<string> res;
  for (string w : words) if (F(w) == F(pattern)) res.push_back(w);
  return res;
}

string F(string w) {
  unordered_map<char, int> m;
  for (char c : w) if (!m.count(c)) m[c] = m.size();
  for (int i = 0; i < w.length(); ++i) w[i] = 'a' + m[w[i]];
  return w;
}
