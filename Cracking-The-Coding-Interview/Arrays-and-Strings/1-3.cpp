// Design an algorithm and write code to remove the duplicate characters in a
// string without using any additional buffer. Write the test cases for this method

#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

void removeDuplicate1(string& s) {
  for(int i = 0; i < s.length(); i++) {
    for(int j = i + 1; j < s.length(); j++) {
      if(s[i] == s[j]) {
        s[j] = '\0';
      }
    }
  }
}

// Time complexity is O(n^2)

void removeDuplicate2(string& s) {
  map<char, int> map;
  for(int i = 0; i < s.length(); i++) {
    if(map[s[i]] > 1) {
      s[i] = '\0';
    } else {
      map[s[i]]++;
    }
  }
}

// Time complexity is O(n)

void removeDuplicate3(string& s) {
  std::sort(s.begin(), s.end());
  for(int i = 0; i < s.length(); i++) {
    if(s[i] == s[i-1]) {
      s[i] = '\0';
    }
  }
}

// No additional buffer

int main()
{
  string s1 = "abcd";
  string s2 = "aaaa";
  string s3 = "";
  string s4 = "aaabbb";
  string s5 = "abababa";
  removeDuplicate3(s1);
  removeDuplicate3(s2);
  removeDuplicate3(s3);
  removeDuplicate3(s4);
  removeDuplicate3(s5);
  cout << s1 << " " << s2 << " " << s3 << " " << s4 << " " << s5 << endl;
  return 0;
}

/* Test Cases:
1 - Repeating character string does not contain, for example: abcd
2 - All repeated string of characters, such as: aaaa
3 - Null string
4 - Consecutive repeating characters, such as: aaabbb
5 - Repeat characters are not consecutive, such as: abababa
*/
