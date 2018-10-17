/* Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a^2 + b^2 = c.

Example 1:
Input: 5
Output: True
Explanation: 1 * 1 + 2 * 2 = 5

Example 2:
Input: 3
Output: False */

bool judgeSquareSum(int c) {
  for(int i=0;i<=sqrt(c);i++) {
      int t=sqrt(c-i*i);
      if(t*t==c-i*i) return true;
  }
  return false;
}
