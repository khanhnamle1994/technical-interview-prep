// Implement an algorithm to determine if a string has all unique characters.
// What if you cannot use additional data structures?

#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

// Brute-force solution O(n^2)
bool isUnique(const string& s) {
  for(int i = 0; i < s.length(); i++) {
    for(int j = i + 1; j < s.length(); j++) {
      if(s[i] == s[j]) {
        return false;
      }
    }
  }
  return true;
}

// Hash-table solution O(n)
bool isUnique1(const string& s) {
  map<char, bool> map;
  for (int i = 0; i < s.length(); i++) {
    if(map[s[i]]) {
      return false;
    } else {
      map[s[i]] = true;
    }
  }
  return true;
}

// No additional data structure O(n)
bool isUnique2(string& s) {
  std::sort(s.begin(), s.end());
  for(int i = 0; i < s.length(); i++) {
    if(s[i] == s[i - 1])
      return false;
  }
  return true;
}

int main()
{
  string s1 = "algorithm";
  string s2 = "alphabetical";
  cout << isUnique2(s1) << " " << isUnique2(s2) << endl;
  return 0;
}
