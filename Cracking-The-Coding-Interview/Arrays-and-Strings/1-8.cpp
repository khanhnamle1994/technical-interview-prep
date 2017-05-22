// Assume you have a method isSubstring which checks if one word is a substring
// of another. Given two strings, s1 and s2, write code to check if s2 is a
// rotation of s1 using only one call to isSubstring

/* Algorithm:
1 - Check if length(s1) == length(s2). If not, return false.
2 - Else, concatenate s1 with itself and see whether s2 is substring of the result.
+ input: s1 = apple, s2 = pleap => apple is a substring of pleappleap
+ input: s1 = apple, s2 = ppale => apple is not a substring of ppaleppale
*/

#include <iostream>
#include <string>
using namespace std;

bool isSubstring(string s1, string s2) {
  if(s1.find(s2) != string::npos) return true;
  else return false;
}

bool isRotation(string s1, string s2) {
  if(s1.length() != s2.length() || s1.length() <= 0)
    return false;
  return isSubstring(s1+s1, s2);
}

int main() {
  string s1 = "waterbottle";
  string s2 = "erbottlewat";
  cout << isRotation(s1, s2) << endl;
  return 0;
}
