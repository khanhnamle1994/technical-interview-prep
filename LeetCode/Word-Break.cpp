/* Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:
>> The same word in the dictionary may be reused multiple times in the segmentation.
>> You may assume the dictionary does not contain duplicate words.

Example 1:
Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:
Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:
Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false */

bool wordBreak(string str, vector<string>& wordDict) {
    unordered_set<int> lengthSolved;
    queue<const char*> q;

    q.push(s.c_str());
    while (q.size()) {
        const char* str = q.front(); q.pop();
        for (auto& word : wordDict) {
            int thisLength = str + word.length() - s.c_str();
            if (lengthSolved.count(thisLength))
                continue;
            if (strncmp(str, word.c_str(), word.length()))
                continue;
            const char *remaining = str + word.length();
            if (*remaining == '\0')
                return true;
            lengthSolved.insert(thisLength);
            q.push(remaining);
        }
    }
    return false;
}
