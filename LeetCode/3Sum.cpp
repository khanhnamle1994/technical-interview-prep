// Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
// Find all unique triplets in the array which gives the sum of zero.

#include <iostream>
using namespace std;

/*
1 - The easiest way of this problem is search every 3 element pairs, after sorting the input array.
It has the complexity O(n^3)

+ The problem requires output that are unique pairs. We can use a flag to test if the current element
is the same as the one in previous iteration, if so, go to the next one and check again. But remember
do not check the element in the first round of iteration.

e.g. 0, 0, 0, 0
In the first round: 1st = [0]; 2nd = 1st + 1 = 0; 3rd = 2nd + 1 = 0; 1st + 2nd + 3rd = 0. find one answer;
here 3rd goes to next element in the array, which is 0, equal to the previous one, so go to the next (which
is the end of the vector), or there will be a duplicate answer.
*/

vector<vector<int>> threeSum(vector<int>& nums) {
  vector<int> res_m(3);
  vector< vector<int> > res;
  vector<int>::iterator it1, it2, it3, iend;

  sort(nums.begin(), nums.end());
  if(nums.size() >= 3) {
    iend = nums.end();
    it1 = nums.begin();
    bool flag1 = false;
    for(it1 != iend; it1++) {
      if(flag1 && (*it1 == *(it1 - 1))) {
        continue;
      }
      flag1 = true;
      bool flag2 = false;
      for(it2 = it1 + 1; it2 != iend; it2++) {
        if(flag2 && (*it2 == *(it2 - 1))) {
          continue;
        }
        flag2 = true;
        bool flag3 = false;
        for(it3 = it2 + 1; it3 != iend; it3++) {
          if(flag3 && (*it3 == *(it3 - 1))) {
            continue;
          }
          flag3 = true;
          if(*it1 + *it2 + *it3 == 0) {
            res_m.at(0) = *it1;
            res_m.at(1) = *it2;
            res_m.at(2) = *it3;
            res.push_back(res_m);
            break;
          }
        }
      }
    }
  }
  return res;
}

/*
2 - The more efficient way: O(n^2)
After sorting the input array, 3 pointers are initialized
The first pointer goes from index 1 to index end - 2
The second pointer goes from the current element (1st pointer) index + 1
The third pointer goes from the last element in a reverse order

Two iterations:
1> 1st pointer from 1 to index end - 2
2> while (2nd < 3rd)

Conditions:
1> if(array[1st] + array[2nd] + array[3rd] == 0), get one result
2> if(array[1st] + array[2nd] + array[3rd] > 0), 3rd - 1
3> if(array[1st] + array[2nd] + array[3rd] < 0), 2nd + 1
*/

vector< vector<int> > threeSum(vector<int> & nums) {
  vector<int> res_m(3);
  vector< vector<int> > res;
  vector<int>::iterator it1, it2, it3, iend;

  sort(nums.begin(), nums.end());

  if(nums.size() >= 3) {
    iend = nums.end();
    it1 = nums.begin();
    bool flag1 = false;

    for(it1 != iend - 2; it1++) {
      if(flag1 && *it1 == *(it1 - 1)) { continue; }

      flag1 = true;
      bool flag2 = false;
      bool flag3 = false;

      it3 = iend - 1;
      it2 = it1 + 1;

      while(it2 != it3) {
        if(flag3 && *it3 == *(it3 + 1)) {
          it3 = it3 - 1;
          continue;
        }

        if(flag2 && *it2 == *(it2 - 1)) {
          it2 = it2 + 1;
          continue;
        }

        if(*it1 + *it2 + *it3 == 0) {
          res_m.at(0) = *it1;
          res_m.at(1) = *it2;
          res_m.at(2) = *it3;
          res.push_back(res_m);
        }

        if(*it1 + *it2 + *it3 > 0) {
          it3 = it3 - 1;
          flag3 = true;
        } else {
          it2 = it2 + 1;
          flag2 = true;
        }
      }
    }
  }
  return res;
}
