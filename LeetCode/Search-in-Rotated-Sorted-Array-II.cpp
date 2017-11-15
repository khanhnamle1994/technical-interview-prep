// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
// Write a function to determine if a given target is in the array.
// The array may contain duplicates.

bool search(vector<int>& nums, int target) {
  int left = 0, right =  nums.size()-1, mid;

  while(left<=right)
  {
      mid = (left + right) >> 1;
      if(nums[mid] == target) return true;

      // the only difference from the first one, trickly case, just updat left and right
      if( (nums[left] == nums[mid]) && (nums[right] == nums[mid]) ) {
        ++left;
        --right;
      }
      else if(nums[left] <= nums[mid])
      {
          if( (nums[left] <= target) && (nums[mid] > target) ) {
            right = mid - 1;
          }
          else {
            left = mid + 1;
          }
      }
      else
      {
          if((nums[mid] < target) &&  (nums[right] >= target) ) {
            left = mid + 1;
          }
          else {
            right = mid - 1;
          }
      }
  }
  return false;
}
