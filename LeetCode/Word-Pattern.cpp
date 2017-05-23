// Given a pattern and a string str, find if str follows the same pattern.

// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

// Examples:
// pattern = "abba", str = "dog cat cat dog" should return true.
// pattern = "abba", str = "dog cat cat fish" should return false.
// pattern = "aaaa", str = "dog cat cat dog" should return false.
// pattern = "abba", str = "dog dog dog dog" should return false.

// Analysis
/* This problem is not hard but needs you be more careful with all the conditions:

- The length of the words in str and chars in pattern may be different
- The char to word is a bijection, which means it is a one-to-one mapping.
- Don't forget to handle the last word when you split the str.

Here for the bijection mapping, I just used two maps, one save (word, char), and the other to save (char, word). */

class Solution {
public:
  bool wordPattern(string pattern, string str) {
    map<char, string> mp1;
    map<string, char> mp2;

    string tmp = "";
    int j = 0;
    for (int i = 0; i <= str.size(); i++) {
      if (j == pattern.size()) {
        return false;
      }
      if (str[i] == ' ' || i == str.size()) {
        if (mp1.find(pattern[j]) == mp1.end() && mp2.find(tmp) == mp2.end()) {
          mp1[pattern[j]] = tmp;
          mp2[tmp] = pattern[j++];
        } else {
          if (mp1[pattern[j]] == tmp && mp2[tmp] == pattern[j]) {
            j++;
          } else {
            return false;
          }
        }
        tmp = "";
      } else {
        tmp += str[i];
      }
    }
    if (j != pattern.size()) { return false; }
    return true;
  }
}
