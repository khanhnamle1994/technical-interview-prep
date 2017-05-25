// Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number.
// The time complexity must be in O(n).

// This question is not difficult, if you know how to find the second largest number, then ask the third-largest number of ideas are
// the same. So we use three variables first, second, third, respectively, to hold the largest, second-largest and third largest number,
// and then we iterate, iterate if the number is greater than the current largest number first, then three variable displacement each
// assignment, if the current number is greater than second, smaller than the first, then update the second and third, if the current
// number is greater than third, less than the second, it would only update third, pay attention to here is a pit, is initialized to use
// a long integer minimum long, or when there is an array INT_MIN present, the program would not know the first maximum value or return
// INT_MIN

class Solution {
public:
  int thirdMax(vector<int>& nums){
    long first = LONG_MIN;
    long second = LONG_MIN;
    long third = LONG_MIN;
    for (int num : nums) {
      if (num > first) {
        third = second;
        second = first;
        first = num;
      }
      if (num > second && num < first) {
        third = second;
        second = num;
      }
      if (num > third && num < second) {
        third = num;
      }
    }
    return (third == LONG_MIN || third == second) ? first : third;
  }
}
