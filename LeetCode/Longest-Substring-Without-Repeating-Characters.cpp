// Given a string, find the length of the longest substring without repeating characters

#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    if(s.length() < 2) return s.length();
    int curlen = 1;
    int maxlen = 1;
    unordered_map<char, int> map;
    map[s[0]] = 0;

    for(int i = 1; i < s.length(); i++) {
      if(map.count(s[i]) == 0 || map[s[i]] < i - curlen) {
        curlen++;
      } else {
        curlen = i - map[s[i]];
      }
      map[s[i]] = i;
      if(curlen > maxlen) {
        maxlen = curlen;
      }
    }

    return maxlen;
  }

};

int main() {
  Solution a;
  string s = "abcadc";
  cout << a.lengthOfLongestSubstring(s) << endl;
}
