// Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2.

/* Example:
Input: [4, 6, 7, 7]
Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]] */

void dfs(vector<vector<int>>& res, vector<int>& seq, vector<int>& nums, int pos) {
  if(seq.size() > 1) res.push_back(seq);
  unordered_set<int> hash;
  for(int i = pos; i < nums.size(); ++i) {
      if((seq.empty() || nums[i] >= seq.back()) && hash.find(nums[i]) == hash.end()) {
          seq.push_back(nums[i]);
          dfs(res, seq, nums, i + 1);
          seq.pop_back();
          hash.insert(nums[i]);
      }
  }
}

vector<vector<int>> findSubsequences(vector<int>& nums) {
  vector<vector<int>> res;
  vector<int> seq;
  dfs(res, seq, nums, 0);
  return res;
}
