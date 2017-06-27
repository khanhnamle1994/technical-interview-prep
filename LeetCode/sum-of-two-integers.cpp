// Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -

class Solution {
public:
    int getSum(int a, int b) {
      if(b == 0) return a;
      int sum = a ^ b; // XOR
      int carry = (a & b) << 1; // AND and bit shift
      int result = getSum(sum, carry);
      return result;
    }
};
