// Write a program that takes an array denoting the daily stock price, and returns the maximum profit that could be made by buying and
// then selling one share of that stock

// Develop algorithms to compute the maximum profit by computing the difference of the current entry with the minimum value seen so far
// as we iterate through the array.

double BuyAndSellStockOnce(const vector<double>& prices) {
  double min_price_so_far = numeric_limits<double>::max(), max_profit = 0;
  for (const double& price : prices) {
    double max_profit_sell_today = price - min_price_so_far;
    max_profit = max(max_profit, max_profit_sell_today);
    min_price_so_far = min(min_price_so_far, price);
  }
  return max_profit;
}

// Time complexity is O(n) and space complexity is O(1), where n is the length of the array.
