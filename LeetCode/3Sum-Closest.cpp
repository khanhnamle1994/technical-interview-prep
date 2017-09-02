// Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
// Return the sum of the three integers. You may assume that each input would have exactly one solution.

// For example, given array S = {-1, 2, 1, -4}, and target = 1.
// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

/* Analysis:
Basically we need to minimize the absolute value of (target – (A[i] + A[j] + A[k]). We follow exactly the same procedure as in
3sum problem by first sorting the whole array and (copyright @sigmainfy) linear scan the rest of the array to find two sum.

If the sum of the triplet is greater than the target, it is obvious that we need to reduce the sum, so set k = k – 1. Similarly
if sum of the triplet is less than the target, then we set j = j + 1, at the same time if we got a sum closer to the target, we
keep record of it.
*/

class Solution {
public:
	int threeSumClosest(vector<int> &num, int target) {
		int diff = INT_MAX, ret = 0;
		sort(num.begin(), num.end());
		int lastIndex = num.size() - 2, j = 0, k = num.size() - 1;
		for (int i = 0; i < lastIndex; ++i) {
			j = i + 1, k = lastIndex + 1;
			while (j < k) {
				int threeSum = num[i] + num[j] + num[k];
				int tmpdiff = threeSum - target;
				if (0 == tmpdiff) return target;
				if (abs(tmpdiff) < diff) diff = abs(tmpdiff), ret = threeSum;
				tmpdiff < 0 ? ++j : --k;
			}
		}
		return ret;
	}
};
