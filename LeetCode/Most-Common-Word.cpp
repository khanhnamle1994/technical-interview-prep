// Given a paragraph and a list of banned words, return the most frequent word that is not in the list of banned words.  It is guaranteed there is at least one word that isn't banned, and that the answer is unique.

// Words in the list of banned words are given in lowercase, and free of punctuation.  Words in the paragraph are not case sensitive.  The answer is in lowercase.

/* Example:
Input:
paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
banned = ["hit"]
Output: "ball"

Explanation:
"hit" occurs 3 times, but it is a banned word.
"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph.
Note that words in the paragraph are not case sensitive,
that punctuation is ignored (even if adjacent to words, such as "ball,"),
and that "hit" isn't the answer even though it occurs more because it is banned. */

string mostCommonWord(string paragraph, vector<string>& banned) {
  unordered_set<string> ban(banned.begin(), banned.end());
  unordered_map<string, int> count;
  for (auto & c: paragraph) c = isalpha(c) ? tolower(c) : ' ';
  istringstream iss(paragraph);
  string w;
  pair<string, int> res ("", 0);
  while (iss >> w)
      if (ban.find(w) == ban.end() && ++count[w] > res.second)
          res = make_pair(w, count[w]);
  return res.first;
}

/* 4 steps:
1 - remove all punctuations
2 - change to lowercase
3 - words count for each word not in banned set
4 - return the most common word */
