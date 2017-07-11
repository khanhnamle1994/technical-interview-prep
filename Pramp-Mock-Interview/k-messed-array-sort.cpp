// Given an array of integers arr where each element is at most k places away from its sorted position, code an efficient function
// sortKMessedArray that sorts arr. For instance, for an input array of size 10 and k = 2, an element belonging to index 6 in the sorted
// array will be located at either index 4, 5, 6, 7 or 8 in the input array.

// Analyze the time and space complexities of your solution.

// Example:
// input:  arr = [1, 4, 5, 2, 3, 7, 8, 6, 10, 9], k = 2
// output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

#include <iostream>
#include <vector>
using namespace std;

/* A simple solution would be to use an efficient sorting algorithm to sort the whole array again. The worst case time complexity of this
approach will be O(N⋅log(N)) where N is the size of the input array. This method also do not use the fact that array is k-sorted.

We can also use insertion sort that will correct the order in just O(N∙K) time. Insertion Sort performs really well for small values of k
but it is not recommended for large value of k (use it for k < 12).

However, we can do better than that. If we use min heap, we can get an asymptotically better time complexity. We can solve this problem in
O(N⋅log(K)). The idea is to construct a min-heap of size k+1 and insert first k+1 elements into the heap. Then we remove min from the heap
and insert next element from the array into the heap and continue the process until both array and heap are exhausted. Each pop operation
from the heap should insert the corresponding top element in its correct position in the array. */

void sortKMessedArray(vector<int>& arr, int k) {
  for(int i = 1; i < arr.size(); i++) {
    int key = arr[i];
    int j = i - 1;

    // Move elements of A[0...i - 1], that are greater than key, to one position ahead of their current position
    // This loop will run at most k times
    while(j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

int main() {
  vector<int> arr;
  arr.push_back(1);
  arr.push_back(4);
  arr.push_back(5);
  arr.push_back(2);
  arr.push_back(3);
  arr.push_back(7);
  arr.push_back(8);
  arr.push_back(6);
  arr.push_back(10);
  arr.push_back(9);

  sortKMessedArray(arr, 2);
  for(int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }
}

// Time Complexity:
// Building a heap takes O(K) time for K+1 elements. Insertion into and extraction from the min-heap take O(log(K)), each. Across all three
// loops, we do at least one of these actions N times, so the total time complexity is O(N⋅log(K)). if K is substantially smaller than N,
// then we can consider log(K) constant and argue that the complexity is practically linear.

// Space Complexity:
// We need to a maintain min-heap of size K+1 throughout the algorithm, so the auxiliary space complexity is O(K).
