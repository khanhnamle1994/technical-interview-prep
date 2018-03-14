// We define a harmonious array is an array where the difference between its maximum value and its minimum value is exactly 1.
// Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible subsequences.

/* Example 1:
Input: [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3]. */

int findLHS(vector<int>& nums) {
  unordered_map<int,int>m;
  for(auto i: nums)
      m[i]++;
  int res = 0;
  for(auto it:m)
      if(m.count(it.first-1)>0)
          res = max(res, it.second+m[it.first-1]);
  return res;
}

// Run time O(n) and Space O(n) use unordered_map
// First loop through all elements and count each number appearance. Then loop through unordered_map, to find if the key - 1 is in the unordered map. If key - 1 and key both in the map, update the result
