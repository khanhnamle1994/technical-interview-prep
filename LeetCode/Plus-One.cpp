// Given a non-negative integer represented as a non-empty array of digits, plus one to the integer. You may assume the integer
// do not contain any leading zero, except the number 0 itself. The digits are stored such that the most significant digit is at
// the head of the list.

/* Analysis:
This problem is pretty easy.
Just consider two special cases:
(1) last digit is 9: need a carry
(2) All the digits are 9 just return 100000... number of 0s is the length of the vector. */

class Solution {
public:
  vector<int> plusOne(vector<int>& digits){
    if(digits[digits.size() - 1] != 9) {
      digits[digits.size() - 1]++;
      return digits;
    } else {
      digits[digits.size() - 1] = 0;
      for (int i = digits.size() - 2; i >= 0; i--) {
        if (digits[i] != 9) {
          digits[i]++;
          return digits;
        } else {
          digits[i] = 0;
        }
      }
      vector<int> res(digits.size() + 1, 0);
      res[0] = 1;
      return res;
    }
  }
}
