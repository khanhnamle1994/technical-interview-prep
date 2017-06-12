// You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails
// the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

// Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

// You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad
// version. You should minimize the number of calls to the API.

/* Analysis:
This is a classical Binary Search problem. Although the first paragraph of problem description seems useless, it still give us an
important condition: all the versions after a bad version are also bad.

What does this mean? For example, since we have the API to return true/false for each position, now we have, say:

[0 0 0 1 1 1 1 1 1 1 1 1 1]

In the above 13 versions, the 4th version is bad and all the versions after neither. The problem now naturally becomes:
Given an array with only 0s and 1s (ture or false), find the first 1, as fast as you could.

OK, now we could easily apply the Binary Search to sovle it! Some of you might face another problem: binary search is to find one specific
number, now there are many 1s in the array, what we should do now?

We know that every time in the binary search, we make decision according to the middle value, the "common" way is directly check the mid
value and the target value. However, now if we met a "1", it is not certain that this "1" is the first "1" in the array. OK, what if we
met a "0"? It is sure that 0 and all the numbers before this 0 are all 0s, and we don't care about them. Therefore, now the conditions are:

+ If we met 0, search the right part.
+ If we met 1, remember the position, and search the left part to see if there is any other 1.

A simple binary search will work well for this problem. */

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    void search(int start, int end, int &res) {
      if (start > end) { return; }
      else {
        int mid = start + (end - start) / 2;
        int tmp = isBadVersion(mid);
        if(tmp) {
          res = mid;
          search(start, mid - 1, res);
        } else {
          search(mid + 1, end, res);
        }
      }
    }

    int firstBadVersion(int n) {
      int res = n;
      search(1, n, res);
      return res;
    }
};
