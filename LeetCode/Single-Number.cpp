// Given an array of integers, every element appears twice except for one. Find that single one.

// Analysis
/*
The requirement is O(n) time and O(1) space. Thus, the  "first sort and then find " way is not working. Also the "hash map" way is not working.
Since we can not sort the array, we shall find a cumulative way, which is not about the ordering.
XOR is a good way, we can use the property that A XOR A = 0, and A XOR B XOR A = B.
So, the code becomes extremely easy.
*/

class Solution {
public:
  int singleNumber(int A[], int n) {
    int res = A[0];
    for(int i = 0; i < n; i++) {
      res = res ^ A[i];
    }
    return res;
  }
}
