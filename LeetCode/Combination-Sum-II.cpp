// Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums
// to T.

// Each number in C may only be used once in the combination.

/* For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
] */

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
  vector<vector<int>> res;
  sort(candidates.begin(),candidates.end());
  vector<int> local;
  findCombination(res, 0, target, local, candidates);
  return res;
}

void findCombination(vector<vector<int>>& res, const int order, const int target, vector<int>& local, const vector<int>& candidates)
{
    if(target == 0)
    {
        res.push_back(local);
        return;
    }
    else
    {
        for(int i = order; i < candidates.size(); i++) // iterative component
        {
            if(candidates[i] > target) return;
            if(i && candidates[i] == candidates[i - 1] && i > order) continue; // check duplicate combination
            local.push_back(candidates[i]),
            findCombination(res, i + 1, target - candidates[i], local, candidates); // recursive componenet
            local.pop_back();
        }
    }
}

// At the beginning, I stuck on this problem. After careful thought, I think this kind of backtracking contains a iterative component and a
// resursive component so I'd like to give more details to help beginners save time. The revursive component tries the elements after the
// current one and also tries duplicate elements. So we can get correct answer for cases like [1 1] 2. The iterative component checks duplicate
// combinations and skip it if it is. So we can get correct answer for cases like [1 1 1] 2.
