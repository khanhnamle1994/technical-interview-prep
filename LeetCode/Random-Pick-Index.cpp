// Given an array of integers with possible duplicates, randomly output the index of a given target number. You can assume that the
// given target number must exist in the array.

/* Example:

int[] nums = new int[] {1,2,3,3,3};
Solution solution = new Solution(nums);

// pick(3) should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
solution.pick(3);

// pick(1) should return 0. Since in the array only nums[0] is equal to 1.
solution.pick(1); */

vector<int> _nums;

Solution(vector<int> nums) {
  _nums = nums;
}

int pick(int target) {
  int n = 0, ans = -1;
  for(int i = 0 ; i < _nums.size(); i++){
      if(_nums[i] != target) continue;
      if(n == 0){
        ans = i;
        n++;
      } else {
          n++;
          if(rand() % n == 0){
            ans = i;
          }// with prob 1/(n+1) to replace the previous index
      }
  }
  return ans;
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
