/* Given an array of integers nums, sort the array in ascending order.

Example 1:
Input: [5,2,3,1]
Output: [1,2,3,5]

Example 2:
Input: [5,1,1,2,0,0]
Output: [0,0,1,1,2,5] */

vector<int> sortArray(vector<int>& nums) {
   int n = nums.size();
   int minEl = nums[0], maxEl = nums[0];
   for (int i = 1; i < n; ++i) {
      if (minEl > nums[i]) minEl = nums[i];
      if (maxEl < nums[i]) maxEl = nums[i];
   }
   vector<int> C(maxEl - minEl + 1);
   for (int i : nums) ++C[i - minEl];
   int j = 0;
   for (int i = 0; i < C.size(); ++i) {
      int el = i + minEl;
      int &cnt = C[i];
      while (cnt--) nums[j++] = el;
   }
   return nums;
}
