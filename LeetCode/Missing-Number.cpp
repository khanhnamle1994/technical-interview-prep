// Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
// For example, given nums = [0, 1, 3] return 2.

// Note: Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

/* Analysis:
First let's take a look at the requirement in the "Note" and review the runtime complexity.  It is required linear. Linear time  == O(n).
Usually, for such problem given an array, O(n) algorithm have constant time of for loop. For this problem, only one loop from the start
to the end should be enough to solve it.

Think about what we have at hand right now:
+ an array of numbers, the length is n.
+ a for loop, with an index int i  i = 0 to n-1
+ The array is NOT sorted!

Since the array should be continuous but now missed one number,  the index i could be used as a reference, by check the i and the values
in array, we don't have to open another spaces to store the array from 0 to n.  However, index i changes every iteration, and the array
is not sorted, how can we save the previous values using only constant extra space?

For this problem, if it reminds you the bit manipulation, I think this problem surprisingly becomes very easy. If you have no idea what
bit manipulation is, let's now take a brief review of one bit operation: XOR.

From the figure below, I show the XOR operation between 0 and 1 in binary. Basically, XOR checks if the two bits are same (return 0 ) or
not (return 1).  For two numbers in decimal, the XOR can be used to check if they are the same,  and return 0.  Also, the XOR between any
number and 0 results in the number itself.  Besides, for more than two decimal numbers, the XOR of all those numbers is not related to the
order.

Therefore, this problem can be solved pretty straightforward by O(n) time, and O(1) space. */

class Solution {
public:
  int missingNumber(vector<int>& nums) {
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
      res = res ^ i;
      res = res ^ nums[i];
    }
  }
}
