// A zero-indexed array A of length N contains all integers from 0 to N-1. Find and return the longest length of set S, where S[i] = {A[i], A[A[i]], A[A[A[i]]], ... } subjected to the rule below.

// Suppose the first element in S starts with the selection of element A[i] of index = i, the next element in S should be A[A[i]], and then A[A[A[i]]]… By that analogy, we stop adding right before a duplicate element occurs in S.

/* Example 1:
Input: A = [5,4,0,3,1,6,2]
Output: 4

Explanation:
A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.

One of the longest S[K]:
S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0} */

// The idea is to, start from every number, find circles in those index-pointer-chains, every time you find a set (a circle) mark every number as visited (-1) so that next time you won’t step on it again.

int arrayNesting(vector<int>& nums) {
  size_t maxsize = 0;
  for (int i = 0; i < nums.size(); i++) {
      size_t size = 0;
      for (int k = i; nums[k] >= 0; size++) {
          int numk = nums[k];
          nums[k] = -1; // mark nums[k] as visited;
          k = numk;
      }
      maxsize = max(maxsize, size);
  }

  return maxsize;
}
