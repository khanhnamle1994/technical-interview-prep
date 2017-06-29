// Given an array of distinct integers and a non-negative integer k, write a function that returns an array of all pairs [x,y]
// such that x - y = k. If no such pairs exist, return an empty array.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int> > findPairsWithGivenDifference(vector<int>& arr, int k) {
  std::sort(arr.begin(), arr.end());
  std::vector<vector<int> > answer;
  int first = 0, last = 1;

  while(last < arr.size() && first < arr.size()) {
    if(first != last && arr[last] - arr[first] == k) {
      vector<int> a;
      a.push_back(arr[first]);
      a.push_back(arr[last]);
      answer.push_back(a);
      last++;
    } else if(arr[last] - arr[first] < k) {
      last++;
    } else if(arr[last] - arr[first] > k) {
      first++;
    }
  }

  return answer;
}

int main() {
  vector<int> arr;
  arr.push_back(0);
  arr.push_back(-1);
  arr.push_back(-2);
  arr.push_back(2);
  arr.push_back(1);

  vector<vector<int> > answer = findPairsWithGivenDifference(arr, 1);

  for(int i = 0; i < answer.size(); i++) {
    cout << '[';
    for(int j = 0; j < answer[i].size(); j++) {
        cout << answer[i][j] << ' ';
    }
    cout << ']';
    cout << endl;
  }
  return 0;
}

/* Time Complexity: the most expensive step in the algorithm is sorting the array, which takes O(n log n) time. The while loop is
O(n) since every iteration increments one of the counters by one. So the total time complexity is O(n log n)

Space Complexity: since the size of the output itself is O(n), the space complexity is O(n) as well. */
