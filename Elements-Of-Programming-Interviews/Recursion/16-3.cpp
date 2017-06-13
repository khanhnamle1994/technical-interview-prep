// This problem is concerned with computing all permutations of an array. Write a program which takes as input an array of distinct integers
// and generates all permutations of that array. No permutation of the array may appear more than once.

/* Solution:
Let the input array be A. Suppose its length is n. A truly brute-force approach would be to enumerate all arrays of length n whose entries
are from A, abd check each such array for being a permutation. This enumeration can be performed recursively, e.g., enumerate all arrays of
length n - 1 whose entries are from A, and then for each array, consider the n arrays of length n which is formed by adding a single entry
to the end of that array. Since the number of possible arrays is n^n, the time and space complexity are staggering.

A better approach is to recognize that once a value has been chosen for an entry, we do not want to repeat it. Specifically, every permutation
of A begins with one of A[0], A[1],..., A[n - 1]. The idea is to generate all permutations that begin with A[0], then all permutations that
begin with A[1], and so on. Computing all permutations beginning with A[0] entails computing all permutations of the updated A[1:n - 1]. We
then restore the original state before embarking on computing all permutations beginning with A[2], and so on. */

vector<vector<int>> Permutations(vector<int> A) {
  vector<vector<int>> result;
  DirectedPermutations(0, &A, &result);
  return result;
}

void DirectedPermutations(int i, vector<int> *A_ptr, vector<vector<int>> *result) {
  vector<int> &A = *A_ptr;
  if(i == A.size() - 1) {
    result->emplace_back(A);
    return;
  }

  // Try every possibility for A[i]
  for(int j = i; j < A.size(); j++) {
    swap(A[i], A[j]);
    // Generate all permutations for A[i + 1 : A.size() - 1]
    DirectedPermutations(i + 1, A_ptr, result);
    swap(A[i], A[j]);
  }
}

// The time complexity is determined by the number of recursive calls, since within each function the time spent is O(1), not including
// the time in the subcalls. The number of function calls, C(n) satisfies the recurrence C(n) = 1 + nC(n - 1) for n >= 1, with C(0) = 1.
// The time complexity T(n) is O(n * n!), since we do O(n) computation per call outside of the recursive calls.
