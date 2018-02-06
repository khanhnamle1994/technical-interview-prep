// Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

/* Example 1:
Input:nums = [1,1,1], k = 2
Output: 2 */

int subarraySum(vector<int>& nums, int k) {
  int cum = 0; // cumulated sum
  unordered_map<int,int> rec; // prefix sum recorder
  int cnt = 0; // number of found subarray
  rec[0]++; // to take into account those subarrays that begin with index 0
  for(int i = 0; i < nums.size(); i++){
      cum += nums[i];
      cnt += rec[cum - k];
      rec[cum]++;
  }
  return cnt;
}
