// Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.

/* Example 1:

Input:
26
Output:
"1a"

Example 2:

Input:
-1
Output:
"ffffffff" */

const string HEX = "0123456789abcdef";

string toHex(int num) {
  if (num == 0) return "0";
  string result;
  int count = 0;
  while (num && count++ < 8) {
      result = HEX[(num & 0xf)] + result;
      num >>= 4;
  }
  return result;
}
