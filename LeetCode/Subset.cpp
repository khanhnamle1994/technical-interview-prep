// Given a set of distinct integers, nums, return all possible subsets.

/* For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
] */

vector<vector<int>> subsets(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int elem_num = nums.size();
    int subset_num = pow(2, elem_num);
    vector<vector<int>> subset_set(subset_num, vector<int>());

    for (int i = 0; i < elem_num; i++) {
      for (int j = 0; j < subset_num; j++) {
        if ((j >> i) & 1) {
          subset_set[j].push_back(nums[i]);
        }
      }
    }

    return subset_set;
}
