/* This time, we place our chess knight on any numbered key of a phone pad (indicated above), and the knight makes N-1 hops.  Each hop must be from one key to another numbered key.

Each time it lands on a key (including the initial placement of the knight), it presses the number of that key, pressing N digits total.

How many distinct numbers can you dial in this manner?

Example 1:
Input: 1
Output: 10

Example 2:
Input: 2
Output: 20

Example 3:
Input: 3
Output: 46 */

int knightDialer(int N) {
    vector<vector<long long>> dp;
    int i, j;
    long long ans = 0;
    int mod = 1000000007;
    for (i = 0 ; i < 2; i++) {
        dp.push_back(vector<long long>(10, 0));
    }


    for (i = 0; i < 10; i++) {
        dp[0][i] = 1;
    }

    for (i = 1 ; i < N; i++) {
        dp[i % 2][0] = (dp[(i - 1) % 2][4] + dp[(i - 1) % 2][6]) % mod;
        dp[i % 2][1] = (dp[(i - 1) % 2][6] + dp[(i - 1) % 2][8]) % mod;
        dp[i % 2][2] = (dp[(i - 1) % 2][7] + dp[(i - 1) % 2][9]) % mod;
        dp[i % 2][3] = (dp[(i - 1) % 2][4] + dp[(i - 1) % 2][8]) % mod;
        dp[i % 2][4] = (dp[(i - 1) % 2][0] + dp[(i - 1) % 2][3] + dp[(i - 1) % 2][9]) % mod;
        dp[i % 2][5] = 0;
        dp[i % 2][6] = (dp[(i - 1) % 2][1] + dp[(i - 1) % 2][7] + dp[(i - 1) % 2][0]) % mod;
        dp[i % 2][7] = (dp[(i - 1) % 2][2] + dp[(i - 1) % 2][6]) % mod;
        dp[i % 2][8] = (dp[(i - 1) % 2][1] + dp[(i - 1) % 2][3]) % mod;
        dp[i % 2][9] = (dp[(i - 1) % 2][4] + dp[(i - 1) % 2][2]) % mod;
    }

    for (i = 0 ; i < 10; i++) {
        ans = (ans + dp[(N - 1) % 2][i]) % mod;
    }
    return ans;
}
