/* Given an array A of non-negative integers, half of the integers in A are odd, and half of the integers are even.

Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even, i is even.

You may return any answer array that satisfies this condition.

Example 1:

Input: [4,2,5,7]
Output: [4,5,2,7]
Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted. */

vector<int> sortArrayByParityII(vector<int>& A) {
  for (int i = 0, j = 1; i < A.size(); i += 2, j += 2) {
      while (i < A.size() && A[i] % 2 == 0) i += 2;
      while (j < A.size() && A[j] % 2 == 1) j += 2;
      if (i < A.size()) swap(A[i], A[j]);
  }
  return A;
}
