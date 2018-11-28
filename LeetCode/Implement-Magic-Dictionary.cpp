/* Implement a magic directory with buildDict, and search methods.

For the method buildDict, you'll be given a list of non-repetitive words to build a dictionary.

For the method search, you'll be given a word, and judge whether if you modify exactly one character into another character in this word, the modified word is in the dictionary you just built.

Example 1:
Input: buildDict(["hello", "leetcode"]), Output: Null
Input: search("hello"), Output: False
Input: search("hhllo"), Output: True
Input: search("hell"), Output: False
Input: search("leetcoded"), Output: False */

unordered_set<string> words;

/** Initialize your data structure here. */
MagicDictionary() {

}

/** Build a dictionary through a list of words */
void buildDict(vector<string> dict) {
  for (string &s:dict) words.insert(s);
}

/** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
bool search(string word) {
  for (int i = 0; i < word.size(); i++) {
      char c = word[i];
      for (int j = 0; j < 26; j++) {
          if (c == j+'a') continue;
          word[i] = j+'a';
          if (words.count(word)) return true;
      }
      word[i] = c;
  }
  return false;
}

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
