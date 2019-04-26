/* Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
1 - Only one letter can be changed at a time.
2 - Each transformed word must exist in the word list. Note that beginWord is not a transformed word.

Example 1:
Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore no possible transformation. */

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    queue<string> todo;
    todo.push(beginWord);
    int ladder = 1;
    while (!todo.empty()) {
        int n = todo.size();
        for (int i = 0; i < n; i++) {
            string word = todo.front();
            todo.pop();
            if (word == endWord) {
                return ladder;
            }
            dict.erase(word);
            for (int j = 0; j < word.size(); j++) {
                char c = word[j];
                for (int k = 0; k < 26; k++) {
                    word[j] = 'a' + k;
                    if (dict.find(word) != dict.end()) {
                        todo.push(word);
                    }
                 }
                word[j] = c;
            }
        }
        ladder++;
    }
    return 0;
}
