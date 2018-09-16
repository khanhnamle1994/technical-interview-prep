// Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

// You may return any answer array that satisfies this condition.

/* Example 1:
Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted. */

vector<int> sortArrayByParity(vector<int>& A) {
  int size = A.size();
  vector<int> res(size, 0);
  int start = 0, end = size - 1;
  for (int i = 0; i < size; i++) {
      if (A[i] % 2 == 1) {
          res[end--] = A[i];
      } else {
          res[start++] = A[i];
      }
  }
  return res;
}
