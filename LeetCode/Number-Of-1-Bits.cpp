// Write a function that takes an unsigned integer and returns the number of '1' bits it has.

class Solution {
public:
  int hammingWeight(uint32_t n) {
    int count = 0;

    while(n) {
      n &= (n - 1);
      count++;
    }

    return count;
  }
}
