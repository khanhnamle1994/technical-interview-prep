// Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors
// in the order red, white and blue. Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

/* Analysis:
This is a relative easy problem.
The goal is to rearrange the array, where 0s are in the 1st part of the array, 1s in the middle, and 2s are in the last part. So, we can
just scan the whole array, when meet 0, put it in the front, when meet 2, put it in the last, and leave 1 alone thus in the middle. 0 and
2's positions are stored and modified each time a swap is performed. */

class Solution {
public:
    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    void sortColors(vector<int>& nums) {
        int red = 0;
        int blue = nums.size() - 1;

        while (red < nums.size() && nums[red] == 0) { red++; }
        while (blue > 0 && nums[blue] == 2) { blue--; }

        int i = red;
        while (i <= blue) {
            if (nums[i] == 0 && i > red) {
                swap(nums, i, red);
                red++;
                continue;
            }
            if (nums[i] == 2) {
                swap(nums, i, blue);
                blue--;
                continue;
            }
            i++;
        }
    }
};
