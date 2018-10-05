// Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.

/* Example 1:
Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75 */

double findMaxAverage(vector<int>& nums, int k) {
  double sum=0, res=INT_MIN;
  for(int i=0;i<nums.size();i++) {
      if(i<k) sum+=nums[i];
      else {
          res=max(sum, res);
          sum+=nums[i]-nums[i-k];
      }
  }
  res=max(sum, res);
  return res/k;
}
