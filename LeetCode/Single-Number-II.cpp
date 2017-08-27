// Given an array of integers, every element appears three times except for one, which appears exactly once.
// Find that single one.

// Analysis:
// The general idea of this problem, is to consider all the numbers bit by bit, count the occurrence of '1' in each bit.
// To get the result, check if the number can be divided by 3 (mod 3 = 0), put '0' if true and '1' otherwise.


#include <iostream>
using namespace std;

int singleNumber(vector<int>& nums) {
  int t1, t2, t3 = 0;

  for(int i = 0; i < nums.size(); i++) {
    t1 = t1 ^ nums[i];
    t2 = t2 | ((t1 ^ nums[i]) & nums[i]);
    t3 = ~(t1 & t2);
    t1 = t1 & t3;
    t2 = t2 & t3;
  }

  return t1;
}
