// Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at
// least twice in the array, and it should return false if every element is distinct.

// One way is to firstly sort the array, and check each two elements to see if they are equal.
// Another way is to utilize the hash map (map in C++ STL), create the map at the same time check if there exists any duplicates.

class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return unique(nums.begin(), nums.end()) != nums.end();
  }
}
