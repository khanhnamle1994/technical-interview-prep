// Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

/* Example 1:

Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]

Output:
[
  "cats and dog",
  "cat sand dog"
]

Example 2:

Input:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]

Output:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
Explanation: Note that you are allowed to reuse a dictionary word.

Example 3:

Input:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]

Output:
[] */

unordered_map<string, vector<string>> m;

vector<string> combine(string word, vector<string> prev){
    for(int i = 0; i < prev.size(); ++i){
        prev[i] += " " + word;
    }
    return prev;
}

vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
  if(m.count(s)) return m[s]; //take from memory
  vector<string> result;
  if(wordDict.count(s)){ //a whole string is a word
      result.push_back(s);
  }
  for(int i = 1; i < s.size(); ++i){
      string word = s.substr(i);
      if(wordDict.count(word)){
          string rem = s.substr(0,i);
          vector<string> prev = combine(word, wordBreak(rem, wordDict));
          result.insert(result.end(), prev.begin(), prev.end());
      }
  }
  m[s] = result; //memorize
  return result;
}
