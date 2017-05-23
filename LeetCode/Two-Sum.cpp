// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// Analysis:
/* The easiest way is to use 2 loops, search every pair of elements, find the result and return the index.
The idea is simple but the complexity is high ( O(n^2) ).

Let's think in another way, the above idea tracks the forward way:   A[i]+A[j]==target. What about the opposite way?   target-A[i]==A[j].
Yep! So for each element A[i], if we know there exists A[j]== target-A[i], and the i<j, then OK!

Thus, we use hash map to store the numbers, scan the whole table and use map.find() function to find the existence of the elements.
Note that the question requires (1) the index order, (2) the index is the array number +1. */

// Code O(n^2)
class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    vector<int> res;
    for (int i = 0; i < numbers.size(); i++) {
      for (int j = i + 1; j < numbers.size(); j++) {
        if (numbers[i] + numbers[j] == target) {
          res.push_back(i+1);
          res.push_back(j+1);
        }
      }
    }
    return res;
  }
}

// Code O(n)
class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    vector<int> res;
    map<int, int> hmap;
    hmap.clear();
    for (int i = 0; i < numbers.size(); i++) {
      hmap[numbers[i]] = i;
    }
    for (int i = 0; i < numbers.size(); i++) {
      if (hmap.find(target - numbers[i]) != hmap.end()) {
        if (i < hmap[target - numbers[i]]) {
          res.push_back(i+1);
          res.push_back(hmap[target - numbers[i]] + 1);
          return res;
        }
        if (i > hmap[target - numbers[i]]) {
          res.push_back(hmap[target - numbers[i]] + 1);
          res.push_back(i+1);
          return res;
        }
      }
    }
  }
}
