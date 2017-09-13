// Given a sorted integer array without duplicates, return the summary of its ranges.

/* Example 1:
Input: [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]

Example 2:
Input: [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"] */

vector<string> summaryRanges(vector<int>& nums) {
  const int size_n = nums.size();
  vector<string> res;

  if (size_n == 0) { return res; }

  for (int i = 0; i < size_n;) {
    int start = i, end = i;
    while (end + 1 < size_n && nums[end + 1] == nums[end] + 1) {
      end++;
    }

    if (end > start) {
      res.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
    } else {
      res.push_back(to_string(nums[start]));
    }
    i = end + 1;
  }
  return res;
}
