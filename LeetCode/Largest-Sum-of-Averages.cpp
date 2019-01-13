/* We partition a row of numbers A into at most K adjacent (non-empty) groups, then our score is the sum of the average of each group. What is the largest score we can achieve?

Note that our partition must use every number in A, and that scores are not necessarily integers.

Example:
Input:
A = [9,1,2,3,9]
K = 3
Output: 20
Explanation:
The best choice is to partition A into [9], [1, 2, 3], [9]. The answer is 9 + (1 + 2 + 3) / 3 + 9 = 20.
We could have also partitioned A into [9, 1], [2], [3, 9], for example.
That partition would lead to a score of 5 + 2 + 6 = 13, which is worse. */

double memo[200][200];

double largestSumOfAverages(vector<int>& A, int K) {
    memset(memo, 0, sizeof(memo));
    int N = A.size();
    double cur = 0;
    for (int i = 0; i < N; ++i) {
        cur += A[i];
        memo[i + 1][1] = cur / (i + 1);
    }
    return search(N, K, A);
}

double search(int n, int k, vector<int>& A) {
    if (memo[n][k] > 0) return memo[n][k];
    if (n < k) return 0; // 14ms to 10ms
    double cur = 0;
    for (int i = n - 1; i > 0; --i) {
        cur += A[i];
        memo[n][k] = max(memo[n][k], search(i, k - 1, A) + cur / (n - i));
    }
    return memo[n][k];
}
