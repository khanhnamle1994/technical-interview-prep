// Given an unsorted array of integers, find the length of longest increasing subsequence.
// For example,
// Given [10, 9, 2, 5, 3, 7, 101, 18],
// The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one
// LIS combination, it is only necessary for you to return the length.

int lengthOfLIS(vector<int>& nums) {
  vector<int> res;
  for(int i = 0; i < nums.size(); i++) {
    auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
    if(it == res.end()) {
      res.push_back(nums[i]);
    } else {
      *it = nums[i];
    }
  }
  return res.size();
}
