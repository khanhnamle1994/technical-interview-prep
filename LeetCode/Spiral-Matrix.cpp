// Given a matrix of m * n elements (m rows, n columns), return all elements of the matrix in spiral order

#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int> >& matrix) {
  vector<int> result;
  if(matrix.size() == 0) { return result; }

  int i; // iterator
  int k = 0; // starting row index
  int m = matrix.size() - 1; // ending row index
  int l = 0; // starting column index
  int n = matrix[0].size() - 1; // ending column index

  while(k <= m && l <= n) {
    // print the first row from the remaining rows
    for(i = l; i <= n; i++) {
      result.push_back(matrix[k][i]);
    }
    k++;

    // print the last column from the remaining columns
    for(i = k; i <= m; i++) {
      result.push_back(matrix[i][n]);
    }
    n--;

    // print the last row from the remaining rows
    if(k <= m) {
      for(i = n; i >= l; i--) {
        result.push_back(matrix[m][i]);
      }
    }
    m--;

    // print the first column from the remaining columns
    if(l <= n) {
      for(i = m; i >= k; i--) {
        result.push_back(matrix[i][l]);
      }
    }
    l++;
  }
  return result;
}
