/* Given an integer array A, you partition the array into (contiguous) subarrays of length at most K.  After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning.

Example 1:
Input: A = [1,15,7,9,2,5,10], K = 3
Output: 84
Explanation: A becomes [15,15,15,9,10,10,10] */

unordered_map<int, int> m;

int dfs(vector<int>& a, int& k, int s, int e) {
    if (s > e) return 0;
    if (m.find(s) != m.end()) return m[s];
    int ans = INT_MIN, cur_max = INT_MIN;
    for (int i = 1; i <= k && s + i - 1 <= e; ++i) {
        cur_max = max(cur_max, a[s + i - 1]);
        int next_max = dfs(a, k, s + i, e);
        ans = max(ans, cur_max * i + next_max);
    }
    return m[s] = ans;
}

int maxSumAfterPartitioning(vector<int>& A, int K) {
    return dfs(a, k, 0, a.size() - 1);
}
