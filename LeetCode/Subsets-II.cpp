// Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

/* For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
] */

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
  vector<vector<int> > totalset = {{}};
  sort(nums.begin(), nums.end());

  for(int i = 0; i < nums.size();) {
      int count = 0; // num of elements are the same
      while(count + i < nums.size() && nums[count + i] == nums[i]) {
        count++;
      }
      int previousN = totalset.size();

      for(int k = 0; k < previousN; k++) {
          vector<int> instance = totalset[k];
          for(int j = 0; j < count; j++) {
              instance.push_back(nums[i]);
              totalset.push_back(instance);
          }
      }
      i += count;
  }
  return totalset;
}
