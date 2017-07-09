/* In the computer world, use restricted resource you have to generate maximum benefit is what we always want to pursue.

For now, suppose you are a dominator of m 0s and n 1s respectively. On the other hand, there is an array with strings consisting of
only 0s and 1s.

Now your task is to find the maximum number of strings that you can form with given m 0s and n 1s. Each 0 and 1 can be used at most
once.*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
        for(string str : strs) {
            int zeros = 0;
            int ones = 0;
            for(char c : str) {
                if (c == '0') {
                    zeros++;
                } else {
                    ones++;
                }
            }
            for(int i = m; i >= zeros; i--) {
                for(int j = n; j >= ones; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
                }
            }
        }
        return dp[m][n];
};
