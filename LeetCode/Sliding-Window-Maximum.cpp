// Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

/* Example:

Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7]
Explanation:

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7 */

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
  priority_queue<pair<int,int>> q;
  for(int i = 0;i < k;i++)
      q.push(make_pair(nums[i],i));

  vector<int> mxintervals;
  for(int i = k;i < nums.size();i++){
      //lazy remove
      while(!q.empty() && q.top().second < i-k)
          q.pop();

      pair<int,int> mx = q.top();
      mxintervals.push_back(mx.first);
      q.push(make_pair(nums[i],i));
  }

  //lazy remove
  while(!q.empty() && q.top().second < nums.size()-k)
      q.pop();

  if(q.size())
      mxintervals.push_back(q.top().first);

  return mxintervals;
}
