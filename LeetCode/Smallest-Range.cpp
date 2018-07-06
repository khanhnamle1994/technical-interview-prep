// You have k lists of sorted integers in ascending order. Find the smallest range that includes at least one number from each of the k lists.

// We define the range [a,b] is smaller than range [c,d] if b-a < d-c or a < c if b-a == d-c.

/* Example 1:
Input:[[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
Output: [20,24]
Explanation:
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24]. */

vector<int> smallestRange(vector<vector<int>>& nums) {
  typedef vector<int>::iterator vi;

  struct comp {
      bool operator()(pair<vi, vi> p1, pair<vi, vi> p2) {
          return *p1.first > *p2.first;
      }
  };

  int lo = INT_MAX, hi = INT_MIN;
  priority_queue<pair<vi, vi>, vector<pair<vi, vi>>, comp> pq;
  for (auto &row : nums) {
      lo = min(lo, row[0]);
      hi = max(hi, row[0]);
      pq.push({row.begin(), row.end()});
  }

  vector<int> ans = {lo, hi};
  while (true) {
      auto p = pq.top();
      pq.pop();
      ++p.first;
      if (p.first == p.second)
          break;
      pq.push(p);

      lo = *pq.top().first;
      hi = max(hi, *p.first);
      if (hi - lo < ans[1] - ans[0])
          ans = {lo, hi};
  }
  return ans;
}
