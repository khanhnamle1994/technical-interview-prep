// Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
// You may assume that the array is non-empty and the majority element always exist in the array.

/* Analysis
This a simple question that hashmap (dict) is all we need.
Construct a hashmap that the key is each element in the num, the value is the occurrence of num.
Check the value while constructing the map can get the result. */

class Solution {
public:
  int majorityElement(vector<int>& nums) {
    map<int, int> mp;
    for (int i = 0; i < nums.size(); i++) {
      if(mp.find(nums[i]) != nums.end()) {
        mp[nums[i]] = 1;
      } else {
        mp[nums[i]] += 1;
      }
      if(mp[nums[i]] > nums.size()/2) {
        return nums[i];
      }
    }
  }
}
