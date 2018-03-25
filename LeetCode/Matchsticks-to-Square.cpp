// Remember the story of Little Match Girl? By now, you know exactly what matchsticks the little match girl has, please find out a way you can make one square by using up all those matchsticks. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.

// Your input will be several matchsticks the girl has, represented with their stick length. Your output will either be true or false, to represent whether you could make one square using all the matchsticks the little match girl has.

/* Example 1:
Input: [1,1,2,2,2]
Output: true
Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.

Example 2:
Input: [3,3,3,3,4]
Output: false
Explanation: You cannot find a way to form a square with all the matchsticks. */

bool makesquare(vector<int>& nums) {
  if (nums.size() < 4) return false;
  int sum = 0;
  for (const int val: nums) {
      sum += val;
  }
  if (sum % 4 != 0) return false;
  sort(nums.begin(), nums.end(), [](const int &l, const int &r){return l > r;}); // second
  vector<int> sidesLength(4, 0);
  return dfs(sidesLength, nums, 0, sum / 4);
}

bool dfs(vector<int> &sidesLength,const vector<int> &matches, int index, const int target) {
    if (index == matches.size())
        return sidesLength[0] == sidesLength[1] && sidesLength[1] == sidesLength[2] && sidesLength[2] == sidesLength[3];
    for (int i = 0; i < 4; ++i) {
        if (sidesLength[i] + matches[index] > target) // first
            continue;
        int j = i;
        while (--j >= 0) // third
            if (sidesLength[i] == sidesLength[j])
                break;
        if (j != -1) continue;
        sidesLength[i] += matches[index];
        if (dfs(sidesLength, matches, index + 1, target))
            return true;
        sidesLength[i] -= matches[index];
    }
    return false;
}
