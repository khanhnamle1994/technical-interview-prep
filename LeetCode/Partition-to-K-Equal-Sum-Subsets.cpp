/* Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.

Example 1:
Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
Output: True
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums. */

bool canPartition(vector<int>& nums, vector<int>& visited, int start_index, int k, int cur_sum, int cur_num, int target){
    if(k==1)return true;
    if(cur_sum == target && cur_num >0 )return canPartition(nums, visited, 0, k-1, 0, 0, target);
    for(int i = start_index; i<nums.size(); i++){
        if(!visited[i]){
            visited[i] = 1;
            if(canPartition(nums, visited, i+1, k, cur_sum + nums[i], cur_num++, target))return true;
            visited[i] = 0;
        }
    }
    return false;
}

bool canPartitionKSubsets(vector<int>& nums, int k) {
    int sum = 0;
    for(int num:nums)sum+=num;
    if(k <= 0 || sum%k != 0)return false;
    vector<int> visited(nums.size(), 0);
    return canPartition(nums, visited, 0, k, 0, 0, sum/k);
}
