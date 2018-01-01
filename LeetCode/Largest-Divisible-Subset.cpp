// Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in
// this subset satisfies: Si % Sj = 0 or Sj % Si = 0.
// If there are multiple solutions, return any subset is fine.

/* Example 1:
nums: [1,2,3]
Result: [1,2] (of course, [1,3] will also be ok)

Example 2:
nums: [1,2,4,8]
Result: [1,2,4,8] */

vector<int> largestDivisibleSubset(vector<int>& nums) {
  sort(nums.begin(), nums.end());

  vector<int> T(nums.size(), 0);
  vector<int> parent(nums.size(), 0);

  int m = 0;
  int mi = 0;

  // for(int i = 0; i < nums.size(); ++i) // if extending by larger elements
  for(int i = nums.size() - 1; i >= 0; --i) {
  // iterate from end to start since it's easier to track the answer index
    // for(int j = i; j >=0; --j) // if extending by larger elements
    for(int j = i; j < nums.size(); ++j) {
      // if(nums[i] % nums[j] == 0 && T[i] < 1 + T[j]) // if extending by larger elements
      // check every a[j] that is larger than a[i]
      if(nums[j] % nums[i] == 0 && T[i] < 1 + T[j]) {
        // if a[j] mod a[i] == 0, it means T[j] can form a larger subset by putting a[i] into T[j]
        T[i] = 1 + T[j];
        parent[i] = j;
        if(T[i] > m) {
          m = T[i];
          mi = i;
        }
      }
    }
  }

  vector<int> ret;
  for(int i = 0; i < m; ++i) {
    ret.push_back(nums[mi]);
    mi = parent[mi];
  }

  // sort(ret.begin(), ret.end()); // if we go by extending larger ends, the largest "answer" element will come first
  // since the candidate element we observe will become larger and larger as i increases in the outermost "for" loop
  // above.
  // alternatively, we can sort nums in decreasing order obviously.
  return ret;
}

/* The key concept here is:
Given a set of integers that satisfies the property that each pair of integers inside the set are mutually divisible,
for a new integer S, S can be placed into the set as long as it can divide the smallest number of the set or is
divisible by the largest number of the set.

For example, let’s say we have a set P = { 4, 8, 16 }, P satisfies the divisible condition. Now consider a new number
2, it can divide the smallest number 4, so it can be placed into the set; similarly, 32 can be divided by 16, the
biggest number in P, it can also placed into P.

Next, let’s define:
For an increasingly sorted array of integers a[1 … n]:
>> T[n] = the length of the largest divisible subset whose largest number is a[n]
>> T[n+1] = max{ 1 + T[i] if a[n+1] mod a[i] == 0 else 1 }

Now, deducting T[n] becomes straight forward with a DP trick. For the final result we will need to maintain a backtrace
array for the answer.
