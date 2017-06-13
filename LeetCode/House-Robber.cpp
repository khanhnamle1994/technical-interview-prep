// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only
// constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically
// contact the police if two adjacent houses were broken into on the same night.

// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob
// tonight without alerting the police.

/* Analysis:
In this problem, it is usually hard for beginers to remind the "dynamic programming” (a.k.a. DP) approach. In order to better illustrate
this specific problem, I tried to draw a figure below to help us understand the problem.  I personally used to look for the “state” in the
problem at first, and then look for the “transition” between the states, then it is often just several lines of code that can solve the DP
problem.

In this problem, every time the robber is in front of a house with his bag of money can be viewed as a “state”, note that at this time,
money bag has the money robber robbed in previous houses. Now, “actions” that robber can take are only two: rob or skip this house. However,
this action is related to some “previous history” which is required by the problem: no adjacent houses is allowed to break. Considering
the robber following certain path to get the max monry, In other words, for current house we have to choose if we rob or skip. If we skip,
we could have the amount of money from the path connected with previous house (which means we also robbed previous house). If we rob
current house, then we cannot take the path connected to previous house, but the 2nd previous is OK.

For those who are familiar with a little DP, the description can be easily extracted as the following:
Given an array of non-negative integers, find the maximum sum of a subset, such that no element is adjacent to the other.

Starting from the above description, we can see that:
1. This problem requires the max sum.
2. Original index of any two elements in the subset cannot be adjacent.

So, from the two observation, we have some further observations:
1. Order is not important. (because we need the sum)
2. For each element (say ith element) in the original array,  i-1 element cannot be included (neither does the i+1 th element).
3. Since all numbers are non-negative, the max sum before ith element (say S[i]), is max(S[i-2], S[i-3]).
    Why not considering S[i-4] S[i-5]... but just the last 2 and last 3 elements?
    Because S[i-2] = max(S[i-4], S[i-5]) + A[i-2], all numbers are >=0
    So S[i-2] >= S[i-5]
4. Therefore, we can write down the DP transition function:
S[i] = max(S[i-2], S[i-3]) + A[i]

The initialization of this problem is pretty straightforward, we use S[i] denote the max sum before A[i+1],  so S[1] = A[0], S[2] = A[1].
The final results is max(S[N], S[N-1]), N is the number of elements in A. */

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len==0) return 0;
        if (len == 1) return nums[0];
        vector<int> s(len+1,0);
        s[1] = nums[0];
        s[2] = nums[1];
        for (int i=3;i<=len;i++){
            s[i] = max(s[i-2],s[i-3]) + nums[i-1];
        }
        return max(s[len-1],s[len]);
    }
};
