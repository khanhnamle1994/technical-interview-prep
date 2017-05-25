// Given an array and a value, remove all instances of that value in place and return the new length.
// Do not allocate extra space for another array, you must do this in place with constant memory.
// The order of elements can be changed. It doesn't matter what you leave beyond the new length.

// Example:
// Given input array nums = [3,2,2,3], val = 3. Your function should return length = 2, with the first two elements of nums being 2.

/* Analysis
Idea is to use double pointer (i and j ), i goes from 1st to the last element in the array, think i scan all the array, and j stores the
final result. e.g.

A = 1 2 3 4 5 3 6 7;
i j are set to start position.

i goes from 1 to 7, if this element is not the element requested,A[j]=A[i] (no change at start because i and j are same.),
then i ++, j++, otherwise, i++, means to skip this element,but j stays, from next element, continue the above step, when set A[j]=A[i],
which means A[j] was originally stored the removed element but now stores the next one.

A = 1 2 3 4 5 3 6 7,  elem=3
       i   i  i
       j   j  j

then
A = 1 2 3 4 5 3 6 7
       i  i      i
       j  j  j

and A = 1 2 4 4 5 3 6 7
                          i
                      j
finally, A= 1 2 4 5 6 7
*/

class Solution: {
public:
  int removeElement(vector<int>& nums, int val) {
    int i = 0, j = 0;
    while (i < nums.size()) {
      if (nums[i] != val) {
        nums[j] = nums[i];
        j++;
      }
      i++;
    }
    return j;
  }
}
