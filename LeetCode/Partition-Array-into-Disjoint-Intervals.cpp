/* Given an array A, partition it into two (contiguous) subarrays left and right so that:

>> Every element in left is less than or equal to every element in right.
>> left and right are non-empty.
>> left has the smallest possible size.

Return the length of left after such a partitioning.  It is guaranteed that such a partitioning exists.

Example 1:
Input: [5,0,3,8,6]
Output: 3
Explanation: left = [5,0,3], right = [8,6]

Example 2:
Input: [1,1,1,0,6,12]
Output: 4
Explanation: left = [1,1,1,0], right = [6,12] */

int partitionDisjoint(vector<int>& A) {
    int end_i = 0;
    int cur_max = A[0];
    int new_max = cur_max;

    // Only change end_i if we find something smaller than cur_max down the line.
    // If we do, then we have to update cur_max to the biggest item in the new left_array.
    // This is still O(N) since we keep track of new_max while iterating.
    for (int i = 1; i < A.size(); i++) {
      new_max = std::max(new_max, A[i]);
      if (A[i] < cur_max) {
        end_i = i;
        cur_max = new_max;
      }
    }

    // Have to return the length of left_array, not the index
    int length_of_left = end_i + 1;
    return length_of_left;
}
