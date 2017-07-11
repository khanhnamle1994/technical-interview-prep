// Given a sorted array arr of distinct integers, write a function indexEqualsValueSearch that returns an index i for which arr[i] == i.
// Return -1 if there is no such index. Analyze the time and space complexities of your solution and explain its correctness.

/* Examples:
input: arr = [-8,0,2,5]
output: 2 # since arr[2] == 2

input: arr = [-1,0,3,6]
output: -1 # since no index in arr satisfies arr[i] == i. */

#include <iostream>
#include <vector>
using namespace std;

int indexEqualsValueSearch(vector<int>& arr) {
  int start = 0;
  int end = arr.size() - 1;

  while(start <= end) {
    int middle = (start + (end - start) / 2);
    if(arr[middle] - middle < 0) {
      start = middle + 1;
    } else if(arr[middle] - middle == 0) {
      return middle;
    } else {
      end = middle - 1;
    }
  }

  return -1;
}

int main() {
  vector<int> arr;
  arr.push_back(-1);
  arr.push_back(0);
  arr.push_back(3);
  arr.push_back(6);

  for(int i = 0; i < arr.size(); i++) {
    cout << arr[i] << endl;
  }

  int result = indexEqualsValueSearch(arr);
  cout << result;
}

/* Solution:
The naive solution is to iterate over all the values in the input array and return an index i for which the condition arr[i] == i is met.
This takes a linear, O(N), time complexity.

To do better, we should recognize that the sequence of i (array indices) and the sequence of arr[i] (array values) are both strictly
monotonically increasing sequences. If we subtract i from both sides of the equation arr[i] = i we get arr[i] - i = 0. In mathematics,
subtracting two strictly monotonically increasing sequences results in a monotonically increasing sequence (not necessarily strict, though).

While we can use this to define another array diffArr where diffArr[i] = arr[i] - i and perform a Binary Search for 0 in diffArr, it’s
unnecessary. Instead, we can simply modify the binary search condition to arr[i] - i == 0 (instead of the condition diffArr[i] == 0).

So why is it important for the search condition to form a monotonically increasing sequence?

It’s important because otherwise there is no guarantee that the resulting sequence is sorted and binary search is guaranteed to work only
sorted sequences. Recall that if an array consists of monotonically increasing values, then it’s sorted by defintion (in an ascending order).

We can now proceed to implementing the algorithm. */

// Time Complexity:
// O(log(N)) since we use a binary search where the input size is reduced in half on each step. Calculating arr[i] - i as the condition
// instead of arr[i] is done in constant time and has no impact on the asymptotic time complexity.

// Space Complexity:
// It’s O(1) since we’re only a constant amount of memory (i.e. the variables start and end).
