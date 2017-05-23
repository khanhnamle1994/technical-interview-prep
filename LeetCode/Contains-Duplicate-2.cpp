// Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that
// nums[i] = nums[j] and the absolute difference between i and j is at most k.

// Same idea as previous question that Hash table is used. The only difference is that the requirement of minimum distance between the
// same elements is at most k. Remember that previous question, we set the value of hash table True/False, in this question, we change
// that to the index of element. Therefore we can keep tracking the distance between the two elements. A simple check can solve the problem.

class Solution {
public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    if(nums.size() == 0) { return false; }
    map<int, int> mp;
    for(int i = 0; i < nums.size(); i++) {
        if(mp.find(nums[i]) == mp.end()) {
            mp[nums[i]] = i;
        } else {
            if(i - mp[nums[i]] <= k) {
                return true;
            } else {
                mp[nums[i]] = i;
            }
        }
    }
    return false;
  }
}
