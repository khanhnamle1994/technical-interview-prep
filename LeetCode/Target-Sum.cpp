// You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer,
// you should choose one from + and - as its new symbol.

// Find out how many ways to assign symbols to make sum of integers equal to target S.

/* Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3.
Output: 5
Explanation:

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3. */

int findTargetSumWays(vector<int>& nums, int S) {
  int sum = accumulate(nums.begin(), nums.end(), 0);
  return sum < S || (sum + S) % 2 ? 0 : subsetSum(nums, (sum + S) / 2);
}

int subsetSum(vector<int> &nums, int S) {
  vector<int> dp(S + 1, 0);
  dp[0] = 1;
  for (int n : nums)
    for (int i = S; i >= n; --i) dp[i] += dp[i - n];
  return dp[S];
}
