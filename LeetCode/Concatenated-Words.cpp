// Given a list of words (without duplicates), please write a program that returns all concatenated words in the given list of words.
// A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.

/* Example:
Input: ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]

Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]

Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats";
 "dogcatsdog" can be concatenated by "dog", "cats" and "dog";
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat". */

vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    unordered_set<string> dict(words.begin(), words.end());
    vector<string> ans;

    function<int(string&,int)> dfs = [&](string& word, int idx) {
        if (idx == word.size()) return 0; // can match to the end of word, so return 0

        string w="";
        for (int i=idx; i < word.size(); i++) {
            w += word[i];

            if (dict.find(w) == dict.end()) continue;
            int counter = dfs(word, i+1);
            // a match occurs if counter is not -1. In this case, return counter+1
      // with the increase symbolizing the current word matched
            if (counter != -1) return counter+1;
        }
        return -1; // no match is possible, so return -1
    };

    for (auto& w : words) {
        if (dfs(w, 0) > 1) ans.push_back(w);
    }

    return ans;
}
