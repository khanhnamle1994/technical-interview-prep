// The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
// Now your job is to find the total Hamming distance between all pairs of the given numbers.

/* Example:
Input: 4, 14, 2

Output: 6

Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
showing the four bits relevant in this case). So the answer will be:
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6. */

int totalHammingDistance(vector<int>& nums) {
  vector<int> bit_count(32,0);
  int res=0;

  for(int i=0;i<nums.size();i++)
  {
      for(int j=0;j<32;j++)
      {
          if((1<<j)&nums[i])
              res+=(i-bit_count[j]++);
          else
              res+=bit_count[j];
      }
  }

  return res;
}
