// Given an input string, reverse the string word by word

// For example, given s = "the sky is blue", return "blue is sky the"

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
  string reverseWords(string s) {
    int sz = s.size();
    int i = 0;
    int j = 0;

    while(i < sz) {
      while(i < sz && s[i] == ' ') {
        i++;
      }
      if(i < sz && j > 0) {
        s[j] = ' ';
        j++;
      }
      int start = j;
      while(i < sz && s[i] != ' ') {
        s[j] = s[i];
        j++;
        i++;
      }
      reverse(s.begin() + start, s.begin() + j);
    }

    s.resize(j);
    reverse(s.begin(), s.end());
    return s;
  }
};

int main() {
  Solution a;
  string s = "the sky is blue";
  cout << a.reverseWords(s) << endl;
}
