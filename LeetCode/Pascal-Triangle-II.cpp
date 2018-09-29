// Given a non-negative index k where k ≤ 33, return the k-th index row of the Pascal's triangle.

vector<int> getRow(int rowIndex) {
  vector<int> A(rowIndex+1, 0);
  A[0] = 1;
  for(int i=1; i<rowIndex+1; i++)
      for(int j=i; j>=1; j--)
          A[j] += A[j-1];
  return A;
}
