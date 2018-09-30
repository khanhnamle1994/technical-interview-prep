// The set S originally contains numbers from 1 to n. But unfortunately, due to the data error, one of the numbers in the set got duplicated to another number in the set, which results in repetition of one number and loss of another number.

// Given an array nums representing the data status of this set after the error. Your task is to firstly find the number occurs twice and then find the number that is missing. Return them in the form of an array.

/* Example 1:
Input: nums = [1,2,2,4]
Output: [2,3] */

vector<int> findErrorNums(vector<int>& nums) {
  for(int i = 0; i<nums.size(); i++){
      while(nums[i] != nums[nums[i] - 1])swap(nums[i], nums[nums[i] - 1]);
  }
  for(int i = 0; i<nums.size() ; i++){
      if(nums[i] != i + 1)return {nums[i], i + 1};
  }
}

// The idea is using array indexing, that is putting each nums[i] into the position with index nums[i] - 1. Then, the array becomes [1,2,3,4,5...,n]. So we can find the duplicate number when nums[i] != i+1.
