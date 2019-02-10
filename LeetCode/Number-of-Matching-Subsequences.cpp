/* Given string S and a dictionary of words words, find the number of words[i] that is a subsequence of S.

Example:
Input:
S = "abcde"
words = ["a", "bb", "acd", "ace"]
Output: 3
Explanation: There are three words in words that are a subsequence of S: "a", "acd", "ace". */

int numMatchingSubseq(string S, vector<string>& words) {
    vector<const char*> waiting[128];
    for (auto &w : words)
        waiting[w[0]].push_back(w.c_str());
    for (char c : S) {
        auto advance = waiting[c];
        waiting[c].clear();
        for (auto it : advance)
            waiting[*++it].push_back(it);
    }
    return waiting[0].size();
}
