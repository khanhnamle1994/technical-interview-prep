// Write a method to decide if two strings are anagrams or not

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

bool isAnagram(string& s1, string& s2) {
  std::sort(s1.begin(), s1.end());
  std::sort(s2.begin(), s2.end());
  return s1 == s2;
}

int main() {
  string s1 = "hello";
  string s2 = "elelh";
  cout << isAnagram(s1, s2) << endl;

  string s3 = "hello";
  string s4 = "oellh";
  cout << isAnagram(s3, s4) << endl;
  return 0;
}
