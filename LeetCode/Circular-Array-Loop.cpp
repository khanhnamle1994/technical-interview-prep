/* You are given a circular array nums of positive and negative integers. If a number k at an index is positive, then move forward k steps. Conversely, if it's negative (-k), move backward k steps. Since the array is circular, you may assume that the last element's next element is the first element, and the first element's previous element is the last element.

Determine if there is a loop (or a cycle) in nums. A cycle must start and end at the same index and the cycle's length > 1. Furthermore, movements in a cycle must all follow a single direction. In other words, a cycle must not consist of both forward and backward movements.

Example 1:
Input: [2,-1,1,2,2]
Output: true
Explanation: There is a cycle, from index 0 -> 2 -> 3 -> 0. The cycle's length is 3.

Example 2:
Input: [-1,2]
Output: false
Explanation: The movement from index 1 -> 1 -> 1 ... is not a cycle, because the cycle's length is 1. By definition the cycle's length must be greater than 1.

Example 3:
Input: [-2,1,-1,-2,-2]
Output: false
Explanation: The movement from index 1 -> 2 -> 1 -> ... is not a cycle, because movement from index 1 -> 2 is a forward movement, but movement from index 2 -> 1 is a backward movement. All movements in a cycle must follow a single direction. */

int advanceBy(int step, int j, vector<int>& nums, int dir) {
    int n = nums.size();
    for (; step > 0; step--) {
        j = (j + nums[j] + n) % n;
        if (nums[j] * dir <= 0)
            return -1;
    }
    return j;
}

bool circularArrayLoop(vector<int>& nums) {
    bool loop = false;
    for (int i = 0; i < nums.size() && !loop; i++)
        if (nums[i]) {
            int j1 = i, j2 = i, dir = nums[i];
            do {
                j1 = advanceBy(1, j1, nums, dir);
                j2 = advanceBy(2, j2, nums, dir);
            } while (j1 >= 0 && j2 >= 0 && j1 != j2);

            if (j1 >= 0 && j2 >= 0 && j1 == j2) {
                if (j1 == advanceBy(1, j1, nums, dir))
                    nums[j1] = 0;
                else
                    loop = true;
            }

            nums[i] = 0;
        }
    return loop;
}
