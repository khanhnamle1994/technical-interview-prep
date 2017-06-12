// Given a positive integer num, write a function which returns True if num is a perfect square else False.

class Solution {
public:
    bool isPerfectSquare(int num) {
      int left = 1;
      int right = num;
      while (left <= right) {
        int mid = left + (right - left) / 2;
        if (mid >= num / mid) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      }
      return left == num / left && num % left == 0;
    }
};

// O(log n) time complexity and O(1) space complexity
