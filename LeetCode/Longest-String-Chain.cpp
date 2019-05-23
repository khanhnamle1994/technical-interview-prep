/* Given a list of words, each word consists of English lowercase letters.

Let's say word1 is a predecessor of word2 if and only if we can add exactly one letter anywhere in word1 to make it equal to word2.  For example, "abc" is a predecessor of "abac".

A word chain is a sequence of words [word_1, word_2, ..., word_k] with k >= 1, where word_1 is a predecessor of word_2, word_2 is a predecessor of word_3, and so on.

Return the longest possible length of a word chain with words chosen from the given list of words.

Example 1:
Input: ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: one of the longest word chain is "a","ba","bda","bdca". */

vector<string> findAllWords(string &a)
{
    vector<string> vec;
    for (int i=0; i<a.size(); ++i)
    {
        vec.push_back(a.substr(0, i) + a.substr(i+1, a.size()-i-1));
    }
    return vec;
}

int longestStrChain(vector<string>& words) {
    // Divides given word in 17 levels, according to their word length.
    vector<vector<string>> levels(17);
    for (auto &word : words)    levels[word.size()].push_back(word);

    unordered_map<string, int> mp;
    for (auto word: words)  mp[word] = 1;

    int ans = 1;
    for (int i=2; i<=16; ++i)
    {
        for (int j=0; j<levels[i].size(); ++j)
        {
            vector<string> diffWords = findAllWords(levels[i][j]);

            for (auto word: diffWords)
            {
                if (mp.find(word) != mp.end())  mp[levels[i][j]] = max(mp[word] + 1, mp[levels[i][j]]);
            }

            ans = max (ans, mp[levels[i][j]]);
        }
    }

    return ans;
}
