/* Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the
elements of nums except nums[i]. Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6]. */
#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> output(n);

    output[n - 1] = 1;
    for(int i = n - 2; i >= 0; i--) {
        output[i] = output[i + 1] * nums[i + 1];
    }

    int left = 1;
    for(int i = 0; i < n; i++) {
        output[i] = output[i] * left;
        left = left * nums[i];
    }

    return output;
}

int main() {
  vector<int> nums;
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(3);
  nums.push_back(4);

  for(int i = 0; i < nums.size(); i++) {
    cout << nums[i] << endl;
  }

  vector<int> output = productExceptSelf(nums);

  for(int i = 0; i < output.size(); i++) {
    cout << output[i] << endl;
  }
}
