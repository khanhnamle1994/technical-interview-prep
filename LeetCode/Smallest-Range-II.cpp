/* Given an array A of integers, for each integer A[i] we need to choose either x = -K or x = K, and add x to A[i] (only once).

After this process, we have some array B.

Return the smallest possible difference between the maximum value of B and the minimum value of B.

Example 1:
Input: A = [1], K = 0
Output: 0
Explanation: B = [1]

Example 2:
Input: A = [0,10], K = 2
Output: 6
Explanation: B = [2,8]

Example 3:
Input: A = [1,3,6], K = 3
Output: 3
Explanation: B = [4,6,3] */

int smallestRangeII(vector<int>& A, int K) {
    sort(A.begin(), A.end());
    int n = A.size(), mx = A[n - 1], mn = A[0], res = mx - mn;
    for (int i = 0; i < n - 1; ++i) {
        mx = max(mx, A[i] + 2 * K);
        mn = min(A[i + 1], A[0] + 2 * K);
        res = min(res, mx - mn);
    }
    return res;
}
