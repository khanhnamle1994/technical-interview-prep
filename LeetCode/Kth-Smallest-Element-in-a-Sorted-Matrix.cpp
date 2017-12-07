// Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in
// the matrix.

// Note that it is the kth smallest element in the sorted order, not the kth distinct element.

/* Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13. */

// Binary Search Solution
int kthSmallest(vector<vector<int>>& matrix, int k) {
  int n = matrix.size();
  int le = matrix[0][0], ri = matrix[n - 1][n - 1];
  int mid = 0;

  while (le < ri) {
    mid = le + (ri - le) / 2;
		int num = 0;
		for (int i = 0; i < n; i++) {
				int pos = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
				num += pos;
		}
		if (num < k) {
				le = mid + 1;
		} else {
				ri = mid;
		}
  }

  return le;
}
