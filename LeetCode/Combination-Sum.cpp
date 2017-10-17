// Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the
// candidate numbers sums to T.

// The same repeated number may be chosen from C unlimited number of times.

/* For example, given candidate set [2, 3, 6, 7] and target 7,
A solution set is:
[
  [7],
  [2, 2, 3]
] */

// Backtracking Solution
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> combination;
    combinationSum(candidates, target, res, combination, 0);
    return res;
}

void combinationSum(vector<int>& candidates, int target, vector<vector<int>> &res, vector<int> &combination, int begin) {
  if (!target) {
    res.push_back(combination);
    return;
  }

  for (int i = begin; i != candidates.size() && target >= candidates[i]; i++) {
    combination.push_back(candidates[i]);
    combinationSum(candidates, target - candidates[i], res, combination, i);
    combination.pop_back();
  }
}
