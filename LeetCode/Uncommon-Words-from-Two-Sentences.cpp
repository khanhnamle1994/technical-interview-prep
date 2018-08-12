// We are given two sentences A and B.  (A sentence is a string of space separated words.  Each word consists only of lowercase letters.)

// A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.

// Return a list of all uncommon words.

// You may return the list in any order.

/* Example 1:

Input: A = "this apple is sweet", B = "this apple is sour"
Output: ["sweet","sour"]

Example 2:

Input: A = "apple apple", B = "banana"
Output: ["banana"] */

vector<string> uncommonFromSentences(string A, string B) {
  unordered_map<string, int> count;
  istringstream iss(A + " " + B);
  while (iss >> A) count[A]++;
  vector<string> res;
  for (auto w: count)
      if (w.second == 1)
          res.push_back(w.first);
  return res;
}
