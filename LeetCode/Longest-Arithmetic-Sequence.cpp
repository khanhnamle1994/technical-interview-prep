/* Given an array A of integers, return the length of the longest arithmetic subsequence in A.

Recall that a subsequence of A is a list A[i_1], A[i_2], ..., A[i_k] with 0 <= i_1 < i_2 < ... < i_k <= A.length - 1, and that a sequence B is arithmetic if B[i+1] - B[i] are all the same value (for 0 <= i < B.length - 1).

Example 1:

Input: [3,6,9,12]
Output: 4
Explanation:
The whole array is an arithmetic sequence with steps of length = 3.

Example 2:

Input: [9,4,7,2,10]
Output: 3
Explanation:
The longest arithmetic subsequence is [4,7,10].

Example 3:

Input: [20,1,15,3,10,5,8]
Output: 4
Explanation:
The longest arithmetic subsequence is [20,15,10,5]. */

int longestArithSeqLength(vector<int>& A) {
    // records where each number in A exists.
    unordered_map<int, vector<int>> pos;
    int n = A.size();
    if ( n < 2) return n;

    //longest arithmetic sequence ending at index i and j.
    vector<vector<int>> dp(n, vector<int>(n, 2));
    for(int i = 0 ; i < A.size(); i++) {
        pos[A[i]].push_back(i);
    }
    int maxlen = 2;
    for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j < i; j++) {
		//desired,A[j], A[i] is the previous target arithmetic sequence
            int desired = 2 * A[j] -  A[i];
            if(pos.count(desired)) {
                auto &v = pos[desired]; //all pos in A where desired exists
                auto idx = lower_bound(v.begin(), v.end(), j);
                auto off = distance(v.begin(), idx) - 1; //find the one that exists before index i
                if (off >= 0) {
                    dp[j][i] = dp[v[off]][j] + 1;
                }
            }
            maxlen = max(maxlen, dp[j][i]);
        }
    }
    return maxlen;
}
