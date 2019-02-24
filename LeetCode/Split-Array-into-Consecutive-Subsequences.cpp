/* You are given an integer array sorted in ascending order (may contain duplicates), you need to split them into several subsequences, where each subsequences consist of at least 3 consecutive integers. Return whether you can make such a split.

Example 1:
Input: [1,2,3,3,4,5]
Output: True
Explanation:
You can split them into two consecutive subsequences :
1, 2, 3
3, 4, 5

Example 2:
Input: [1,2,3,3,4,4,5,5]
Output: True
Explanation:
You can split them into two consecutive subsequences :
1, 2, 3, 4, 5
3, 4, 5

Example 3:
Input: [1,2,3,4,4,5]
Output: False */

bool isPossible(vector<int>& nums) {
    unordered_map<int,int> cnt, tails;
    for(int &i : nums) cnt[i]++;
    for(int &i : nums){
        if(!cnt[i]) continue;
        cnt[i]--;
        if(tails[i-1] > 0){
            tails[i-1]--;
            tails[i]++;
        }
        else if(cnt[i+1] && cnt[i+2]){
            cnt[i+1]--;
            cnt[i+2]--;
            tails[i+2]++;
        }
        else return false;
    }
    return true;
}
