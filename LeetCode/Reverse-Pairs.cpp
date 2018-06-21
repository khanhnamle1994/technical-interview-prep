// Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].
// You need to return the number of important reverse pairs in the given array.

/* Example1:

Input: [1,3,2,3,1]
Output: 2

Example2:

Input: [2,4,3,5,1]
Output: 3 */

int reversePairs(vector<int>& nums) {
    vector<int> sortedNums;
    int res = 0, target = 0, pos = 0;
    for (int i = nums.size() - 1; i >= 0; --i) {
        target = nums[i] > 0 ? (nums[i] - 1) / 2 : nums[i] / 2 - 1;
        // find the target that is approximately nums[i]/2 in the sorted array
        auto ptr = upper_bound(sortedNums.begin(), sortedNums.end(), target);
        res += ptr - sortedNums.begin();
        // the number of reverse pair for nums[i] (j > i elements in nums are already sorted in "sortedNums")
        pos = upper_bound(sortedNums.begin(), sortedNums.end(), nums[i]) - sortedNums.begin();
        // insert nums[i] in "sortedNums"
        sortedNums.insert(sortedNums.begin() + pos, nums[i]);
    }
    return res;
}
