// Implement an algorithm to determine if a string has all unique characters.
// What if you cannot use additional data structures?

#include <iostream>
#include <cstring>
using namespace std;

// If we assume that the character set is an ASCII character, then we can open a
// bool array of size 256 to characterize the appearance of each character. The
// array is intialized to false, traversing the characters in the string, and
// when the value of the corresponding position of the bool array is true, indicating
// that the character has already appeared before, it is possible to derive duplicate
// characters in the string. Otherwise, set the value of the bool array to true.

bool isUnique1(string s)
{
  bool a[256];
  memset(a, 0, sizeof(a));
  int len = s.length();
  for(int i = 0; i < len; i++)
  {
    int v = (int)s[i];
    if(a[v]) return false;
    a[v] = true;
  }
  return true;
}

// Time complexity of the algorithm is O(n)

int main()
{
  string s1 = "algorithm";
  string s2 = "alphabetical";
  cout << isUnique1(s1) << " " << isUnique1(s2) << endl;
  return 0; 
}
