/* Given an unsorted array of integers, find the number of longest increasing subsequence.

Example 1:
Input: [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3, 5, 7].

Example 2:
Input: [2,2,2,2,2]
Output: 5
Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5. */

int findNumberOfLIS(vector<int>& nums) {
    int size = nums.size();
    if (size<2) return size;

    int result = 0;
    int longest = 0;
    vector<int> dp(size,1);
    vector<int> dpfreq(size,1);

    for (int i=1 ; i<size ; i++) {
        int freq = 1;
        for (int j=0 ; j<i ; j++) {
            if (nums[i]>nums[j]) {
                if (dp[i]==dp[j]+1) {
                    dpfreq[i] += dpfreq[j];
                }
                else if (dp[i]<dp[j]+1) {
                    dp[i] = dp[j]+1;
                    dpfreq[i] = dpfreq[j];
                }
            }
        }
        if (longest==dp[i]) {
            result+=dpfreq[i];
        }
        else if (longest<dp[i]) {
            longest = dp[i];
            result = dpfreq[i];
        }
    }
    if (longest==1)
        return size;

    return result;
}
