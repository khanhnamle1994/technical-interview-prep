/* Given an array consists of non-negative integers, your task is to count the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.

Example 1:
Input: [2,2,3,4]
Output: 3
Explanation:
Valid combinations are:
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3 */

int triangleNumber(vector<int>& nums) {
  vector<int> snums(nums);
  sort(snums.begin(), snums.end());
  int count = 0;
  for ( int n = nums.size(), k = n - 1; k > 1; --k ) {
      int i = 0, j = k - 1;
      while ( i < j ) {
          // any value x between i...j will satisfy snums[x] + snums[j] > snums[k]
          // and because snums[k] > snums[j] > snums[x] >= 0, they will always satisfy
          // snums[k] + snums[x] > snums[j] and snums[k] + snums[j] > snums[x]
          if ( snums[i] + snums[j] > snums[k] )
              count += --j - i + 1;
          else
              ++i;
      }
  }
  return count;
}
