// Say you have an array for which the ith element is the price of a given stock on day i.
// If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to
// find the maximum profit.

/* Analysis:
The idea is very simple: buy the stock at a lower price and sell it at a higher price in the future.
The easiest way is try to sell the stock from the 2nd day to the last day, and get the highest profit. For each sell day, get the lowest
price before and compute the profit. The algorithm contains two loop, one from the second day to the last, and one from the first day to
the current sell day. The complexity is O(n^2).

A better way. How to reduce the complexity ? Similar idea as above but pre-compute the minimum value for each day, which means for each
day, compute and store the minimum price of the previous days. In this step the complexity is O(n). Then scan all the days to get the max
profit,  total complexity is still O(n). */

// O(n^2) solution
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int res = 0;
        if (prices.size() > 1){
            vector<int>::iterator it1,it2;
            for (it1 = prices.begin() + 1; it1 != prices.end(); it1++){
                for (it2 = prices.begin(); it2 != it1; it2++){
                    if ((*it1 - *it2) > res) {
                        res = *it1 - *it2;
                    }
                }
            }
        }
        return res;
    }
};

// O(n) solution
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int res = 0;
        if (prices.size() > 1){
            vector<int>::iterator it1,it2;
            vector<int> minv;
            int min1=prices[0];
            for (it1 = prices.begin() + 1; it1 != prices.end(); it1++){
                if (*it1 < min1) {
                  min1 = *it1;
                }
                minv.push_back(min1);
            }
            for (int i = 1; i < prices.size(); i++){
                if (prices[i] - minv[i - 1] > res){
                  res = prices[i] - minv[i - 1];
                }
            }
        }
        return res;
    }
};
