// You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest
// number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the
// coins, return -1.

/* Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1. */

// Time: O(n * amount), Space: O(amount) - Dynamic Programming Solution

int coinChange(vector<int>& coins, int amount) {
  int Max = amount + 1;
  vector<int> dp(amount + 1, Max);
  dp[0] = 0;

  for (int i = 1; i <= amount; i++) {
      for (int j = 0; j < coins.size(); j++) {
          if (coins[j] <= i) {
              dp[i] = min(dp[i], dp[i - coins[j]] + 1);
          }
      }
  }
  return dp[amount] > amount ? -1 : dp[amount];
}
