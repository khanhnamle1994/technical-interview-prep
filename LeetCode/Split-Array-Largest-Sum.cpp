// Given an array which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays. Write an algorithm to minimize the largest sum among these m subarrays.

/* Examples:

Input:
nums = [7,2,5,10,8]
m = 2

Output:
18

Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18. */

int splitArray(vector<int>& nums, int m) {
    int len = nums.size();
    vector<vector<long>> arr(m, vector<long>(len, 0));
    arr[0][0] = nums[0];
    for(int i = 1; i<len; i++)
    {
        arr[0][i] = arr[0][i - 1] + nums[i];
    }

    for(int k = 1; k<m; k++)
    {
        for(int i = 0; i<len; i++)
        {
            long minVal = arr[0][i];
            for(int j = i-1; j>= 0; j--)
            {
                long tmpVal = max(arr[0][i] - arr[0][j], arr[k - 1][j]);
                minVal = min(minVal, tmpVal);
            }
            arr[k][i] = minVal;
        }
    }
    return arr[m-1][len - 1];
}
