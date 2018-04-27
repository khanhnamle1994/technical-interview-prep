// Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

// Find the maximum coins you can collect by bursting the balloons wisely.

/* Example:

Given [3, 1, 5, 8]

Return 167

    nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
   coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167 */

int maxCoins(vector<int>& nums) {
  nums.insert(nums.begin(), 1), nums.insert(nums.end(), 1);   // add 1 at both first and last for convenience
  int len = nums.size(), dp[len][len]{};          // dp[l][r] is the max result of nums[l - r] inclusively

  for (int r = 1, end = len - 1; r < end; r++)
      for (int l = r; l > 0; l--)
          for (int k = l; k <= r; k++)            // treat k as the last balloons bursted
              dp[l][r] = max(dp[l][r], dp[l][k - 1] + nums[l - 1] * nums[k] * nums[r + 1] + dp[k + 1][r]);

  return dp[1][len - 2];
}
