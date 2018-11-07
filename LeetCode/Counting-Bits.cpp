/* Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example 1:

Input: 2
Output: [0,1,1]
Example 2:

Input: 5
Output: [0,1,1,2,1,2] */

vector<int> countBits(int num) {
  vector<int> ret(num+1, 0);
  for (int i = 1; i <= num; ++i)
      ret[i] = ret[i&(i-1)] + 1;
  return ret;
}
