// The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
// Now your job is to find the total Hamming distance between all pairs of the given numbers.

/* Example:
Input: 4, 14, 2

Output: 6

Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
showing the four bits relevant in this case). So the answer will be:
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6. */

int totalHammingDistance(vector<int>& nums) {
  int size = nums.size();
  if(size < 2) return 0;
  int ans = 0;
  int *zeroOne = new int[2];
  while(true)
  {
      int zeroCount = 0;
      zeroOne[0] = 0;
      zeroOne[1] = 0;
      for(int i = 0; i < nums.size(); i++)
      {
          if(nums[i] == 0) zeroCount++;
          zeroOne[nums[i] % 2]++;
          nums[i] = nums[i] >> 1;
      }
      ans += zeroOne[0] * zeroOne[1];
      if(zeroCount == nums.size()) return ans;
}
