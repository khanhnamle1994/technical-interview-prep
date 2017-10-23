// Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

// Formally the function should: Return true if there exists i, j, k such that arr[i] < arr[j] < arr[k] given
// 0 ≤ i < j < k ≤ n-1 else return false.

// Your algorithm should run in O(n) time complexity and O(1) space complexity.

/* Examples:
Given [1, 2, 3, 4, 5], return true.
Given [5, 4, 3, 2, 1], return false. */

bool increasingTriplet(vector<int>& nums) {
    int c1 = INT_MAX, c2 = INT_MAX;
    for(int x : nums) {
      if(x <= c1) {
        c1 = x; // c1 is min seen so far (it's a candidate for 1st element)
      } else if(x <= c2) { // here when x > c1, i.e. x might be either c2 or c3
        c2 = x; // x is better than the current c2, store it
      } else { // here when we have/had c1 < c2 already and x > c2
        return true; // the increasing subsequence of 3 elements exists
      }
    }
    return false;
}
