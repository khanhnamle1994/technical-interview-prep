// Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

// For example,
// Given [100, 4, 200, 1, 3, 2],
// The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

// Your algorithm should run in O(n) complexity.

int longestConsecutive(vector<int>& nums) {
  unordered_set<int> s(nums.begin(), nums.end()), searched;
  int longest = 0;
  for (int i: nums) {
      if (searched.find(i) != searched.end()) continue;
      searched.insert(i);
      int j = i - 1, k = i + 1;
      while (s.find(j) != s.end()) searched.insert(j--);
      while (s.find(k) != s.end()) searched.insert(k++);
      longest = max(longest, k - 1 - j);
  }
  return longest;
}
