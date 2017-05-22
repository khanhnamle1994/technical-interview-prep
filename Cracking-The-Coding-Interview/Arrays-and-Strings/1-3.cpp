// Design an algorithm and write code to remove the duplicate characters in a
// string without using any additional buffer. Write the test cases for this method

#include <iostream>
#include <cstring>
using namespace std;

void removeDuplicate1(char s[])
{
  int len = strlen(s);
  if (len < 2) return;
  int p = 0;
  for(int i = 0; i < len; i++)
  {
    if(s[i] != '\0')
    {
      s[p++] = s[i];
      for(int j = i + 1; j < len; j++)
        if(s[j] == s[i])
          s[j] = '\0';
    }
  }
  s[p] = '\0';
}

// Time complexity is O(n^2)

void removeDuplicate2(char s[])
{
  int len = strlen(s);
  if(len < 2) return;
  bool c[256];
  memset(c, 0, sizeof(c));
  int p = 0;
  for(int i = 0; i < len; i++)
  {
    if(!c[s[i]])
    {
      s[p++] = s[i];
      c[s[i]] = true;
    }
  }
  s[p] = '\0';
}

// Time complexity is O(n)

int main()
{
  char s1[] = "abcde";
  char s2[] = "aaabbb";
  char s3[] = "";
  char s4[] = "abababc";
  char s5[] = "ccccc";
  removeDuplicate1(s1);
  removeDuplicate1(s2);
  removeDuplicate1(s3);
  removeDuplicate1(s4);
  removeDuplicate1(s5);
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
