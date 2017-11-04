// Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

/* Example:
(1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6].
(2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2]. */

void wiggleSort(vector<int>& nums) {
  if (nums.empty()) {
		return;
	}
	int n = nums.size();

	// Step 1: Find the median
	vector<int>::iterator nth = next(nums.begin(), n / 2);
	nth_element(nums.begin(), nth, nums.end());
	int median = *nth;

	// Step 2: Tripartie partition within O(n)-time & O(1)-space.
	auto m = [n](int idx) { return (2 * idx + 1) % (n | 1); };
	int first = 0, mid = 0, last = n - 1;
	while (mid <= last) {
		if (nums[m(mid)] > median) {
			swap(nums[m(first)], nums[m(mid)]);
			++first;
			++mid;
		}
		else if (nums[m(mid)] < median) {
			swap(nums[m(mid)], nums[m(last)]);
			--last;
		}
		else {
			++mid;
		}
	}
}
