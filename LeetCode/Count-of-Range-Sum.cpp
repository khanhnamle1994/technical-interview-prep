// Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
// Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.

/* Example:
Given nums = [-2, 5, -1], lower = -2, upper = 2,
Return 3.
The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums are: -2, -1, 2. */

int countRangeSum(vector<int>& nums, int lower, int upper) {
  map<long, int> prefix;
  prefix[0] = 1;

  long sum = 0;
  int res = 0;

  for(int i=0; i<nums.size(); ++i){
      sum += nums[i];
      auto upper_it = prefix.upper_bound(sum - lower);
      auto lower_it = prefix.lower_bound(sum - upper);

      for(; upper_it!=lower_it; ++lower_it){
          res += lower_it->second;
      }

      prefix[sum] += 1;
  }
  return res;
}

// For an index i, sum_now denotes the sum of [nums[0], nums[i]]. sum_prev denotes all the sums of [nums[0], nums[j]] for j in the range of [0, i).
// We keep sum_prev in a map structrue. We need to find sum_prev that in the range of [sum_now - upper, sum_now - lower] for each sum_now.
