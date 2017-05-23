// Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at
// least twice in the array, and it should return false if every element is distinct.

class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return unique(nums.begin(), nums.end()) != nums.end();
  }
}
