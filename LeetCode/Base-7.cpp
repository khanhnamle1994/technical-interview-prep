// Given an integer, return its base 7 string representation.

/* Example 1:
Input: 100
Output: "202"

Example 2:
Input: -7
Output: "-10" */

string convertToBase7(int num) {
  return num >= 0 ? num >= 7 ? convertToBase7(num / 7) + to_string(num % 7) : to_string(num) : '-' + convertToBase7(-num);
}
