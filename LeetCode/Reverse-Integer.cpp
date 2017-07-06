// Reverse digits of an integer
// Example 1: x = 123, return 321
// Example 2: x = -123, return -321

// Note: The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.

#include <iostream>
#include <climits>
using namespace std;

int reverse(int x) {
  int y = 0;
  while (x != 0) {
    if(y > INT_MAX / 10 || y < INT_MIN / 10) { return 0; }
    y = y * 10;
    y = y + (x % 10);
    x = x / 10;
  }
  return y;
}

int main() {
  int x = -123;
  int y = reverse(x);
  cout << y;
  return 0;
}
