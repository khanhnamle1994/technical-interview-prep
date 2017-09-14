// Given a collection of distinct numbers, return all possible permutations.

/* For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
] */

vector<vector<int> > permute(vector<int> &nums) {
	vector<vector<int> > result;

	permuteRecursive(nums, 0, result);
	return result;
}

// permute num[begin..end]
// invariant: num[0..begin-1] have been fixed/permuted
void permuteRecursive(vector<int> &nums, int begin, vector<vector<int> > &result)	{
  if (begin >= nums.size()) {
		  // one permutation instance
		  result.push_back(nums);
		  return;
  }

	for (int i = begin; i < nums.size(); i++) {
		  swap(nums[begin], nums[i]);
		  permuteRecursive(num, begin + 1, result);
		  // reset
		  swap(nums[begin], nums[i]);
	}
}
