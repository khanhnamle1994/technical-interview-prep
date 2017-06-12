// Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

// The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.
// Please note that your returned answers (both index1 and index2) are not zero-based.

// You may assume that each input would have exactly one solution and you may not use the same element twice.

// Input: numbers = {2, 7, 11, 15}, target = 9
// Output: index1 = 1, index2 = 2

/* Analysis:
Since the numbers in array are already sorted, the smallest number is the 1st element, while the largest number is the last. The maximum
sum we can get is the  A[start] + A[end]. Once we move the “start” pointer, the sum increases and the sum is going to decrease if we move
the “end” pointer to the left.

Therefore, we can just move the two pointers and check the sum each time with the target sum, then the result is obtained by only one loop. */

class Solution {
public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> res;
    int left = 0;
    int right = numbers.size() - 1;

    while(left < right) {
      if(numbers[left] + numbers[right] < target) {
        left++;
      } else if(numbers[left] + numbers[right] > target) {
        right--;
      } else {
        res.push_back(left + 1);
        res.push_back(right + 1);
        break;
      }
    }
    return res;
  }
}
