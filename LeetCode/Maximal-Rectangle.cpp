// Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

/* For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Return 6. */

int maximalRectangle(vector<vector<char>>& matrix) {
  if(matrix.empty()) return 0;

  const int m = matrix.size();
  const int n = matrix[0].size();

  int left[n], right[n], height[n];

  fill_n(left,n,0); fill_n(right,n,n); fill_n(height,n,0);

  int maxA = 0;

  for(int i=0; i<m; i++) {
      int cur_left=0, cur_right=n;

      for(int j=0; j<n; j++) { // compute height (can do this from either side)
          if(matrix[i][j]=='1') height[j]++;
          else height[j]=0;
      }

      for(int j=0; j<n; j++) { // compute left (from left to right)
          if(matrix[i][j]=='1') left[j]=max(left[j],cur_left);
          else {left[j]=0; cur_left=j+1;}
      }

      // compute right (from right to left)
      for(int j=n-1; j>=0; j--) {
          if(matrix[i][j]=='1') right[j]=min(right[j],cur_right);
          else {right[j]=n; cur_right=j;}
      }

      // compute the area of rectangle (can do this from either side)
      for(int j=0; j<n; j++)
          maxA = max(maxA,(right[j]-left[j])*height[j]);
  }
  return maxA;
}
