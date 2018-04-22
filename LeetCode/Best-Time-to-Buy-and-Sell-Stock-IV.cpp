// Say you have an array for which the ith element is the price of a given stock on day i.

// Design an algorithm to find the maximum profit. You may complete at most k transactions.

int maxProfit(int k, vector<int>& prices) {
  int n = (int)prices.size(), ret = 0, v, p = 0;
  priority_queue<int> profits;
  stack<pair<int, int> > vp_pairs;

  while (p < n) {
      // find next valley/peak pair
      for (v = p; v < n - 1 && prices[v] >= prices[v+1]; v++);
      for (p = v + 1; p < n && prices[p] >= prices[p-1]; p++);

      // save profit of 1 transaction at last v/p pair, if current v is lower than last v
      while (!vp_pairs.empty() && prices[v] < prices[vp_pairs.top().first]) {
          profits.push(prices[vp_pairs.top().second-1] - prices[vp_pairs.top().first]);
          vp_pairs.pop();
      }

      // save profit difference between 1 transaction (last v and current p) and 2 transactions (last v/p + current v/p),
      // if current v is higher than last v and current p is higher than last p
      while (!vp_pairs.empty() && prices[p-1] >= prices[vp_pairs.top().second-1]) {
          profits.push(prices[vp_pairs.top().second-1] - prices[v]);
          v = vp_pairs.top().first;
          vp_pairs.pop();
      }
      vp_pairs.push(pair<int, int>(v, p));
  }

  // save profits of the rest v/p pairs
  while (!vp_pairs.empty()) {
      profits.push(prices[vp_pairs.top().second-1] - prices[vp_pairs.top().first]);
      vp_pairs.pop();
  }

  // sum up first k highest profits
  for (int i = 0; i < k && !profits.empty(); i++) {
      ret += profits.top();
      profits.pop();
  }
  return ret;
}

// We can find all adjacent valley/peak pairs and calculate the profits easily. Instead of accumulating all these profits like Buy and Sell Stock II, we need the highest k ones.

// The key point is when there are two v/p pairs (v1, p1) and (v2, p2), satisfying v1 <= v2 and p1 <= p2, we can either make one transaction at [v1, p2], or make two at both [v1, p1] and [v2, p2]. The trick is to treat [v1, p2] as the first transaction, and [v2, p1] as the second. Then we can guarantee the right max profits in both situations, p2 - v1 for one transaction and p1 - v1 + p2 - v2 for two.

// Finding all v/p pairs and calculating the profits takes O(n) since there are up to n/2 such pairs. And extracting k maximums from the heap consumes another O(klgn).
