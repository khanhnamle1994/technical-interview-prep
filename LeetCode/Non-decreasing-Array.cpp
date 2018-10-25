// Given an array with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.

// We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).

/* Example 1:
Input: [4,2,3]
Output: True
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
Example 2:
Input: [4,2,1]
Output: False
Explanation: You can't get a non-decreasing array by modify at most one element. */

bool checkPossibility(vector<int>& nums) {
  int cnt = 0;                                                                    //the number of changes
  for(int i = 1; i < nums.size() && cnt<=1 ; i++){
      if(nums[i-1] > nums[i]){
          cnt++;
          if(i-2<0 || nums[i-2] <= nums[i])nums[i-1] = nums[i];                    //modify nums[i-1] of a priority
          else nums[i] = nums[i-1];                                                //have to modify nums[i]
      }
  }
  return cnt<=1;
}
