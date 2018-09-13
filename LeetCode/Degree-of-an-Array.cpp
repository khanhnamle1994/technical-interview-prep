// Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

// Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

/* Example 1:
Input: [1, 2, 2, 3, 1]
Output: 2
Explanation:
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.

Example 2:
Input: [1,2,2,3,1,4,2]
Output: 6 */

int findShortestSubArray(vector<int>& nums) {
  unordered_map<int,vector<int>> mp;
  for(int i=0;i<nums.size();i++) mp[nums[i]].push_back(i);
  int degree=0;
  for(auto it=mp.begin();it!=mp.end();it++) degree=max(degree,int(it->second.size()));
  int shortest=nums.size();
  for(auto it=mp.begin();it!=mp.end();it++)
  {
      if(it->second.size()==degree)
      {
          shortest=min(shortest,it->second.back()-it->second[0]+1);
      }
  }
  return shortest;
}
