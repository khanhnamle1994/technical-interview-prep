// Determine whether an integer is a palindrome. Do this without extra space

// Could negative integers be palindromes? (ie, -1)
// If you are thinking of converting the integer to string, note the restriction of using extra space.
// You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed
// integer might overflow. How would you handle such case?
// There is a more generic way of solving this problem.

#include <iostream>
using namespace std;

bool isPalindrome(int x) {
  if (x < 0) {
    return false;
  } else if (x == 0) {
    return true;
  } else {
    int tmp = x;
    int y = 0;

    while(x != 0) {
      y = y * 10 + x % 10;
      x = x / 10;
    }

    if(y == tmp) { return true; }
    else { return false; }
  }
}
