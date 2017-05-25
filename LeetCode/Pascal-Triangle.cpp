// Given numRows, generate the first numRows of Pascal's triangle.

/* For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

/* Analysis:
In each row, the first and last element are 1. And the other element is the sum of the two elements in the previous row. e.g.

   1 3 3 1   Previous row
1 1+3 3+3 3+1 1   Next row

   1 4 6 4 1 Previous row
1 1+4 4+6 6+4 4+1 1 Next row

So the idea is simple:
(1) Add 1 to current row.
(2) Get the previous line. Sum every two elements and add to current row.
(3) Add 1 to current row.
(4) Go fill the next row
*/

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    
    if(numRows == 0) { return res; }
    vector<int> r;
    r.push_back(1);
    res.push_back(r);

    if(numRows == 1) { return res; }
    r.push_back(1);
    res.push_back(r);

    if(numRows == 2) { return res; }

    for (int i = 2; i < numRows; i++) {
      vector<int> c(i + 1, 1);
      for (int j = 1; j < i; j++) {
        c[j] = res[i-1][j] + res[i-1][j-1];
      }
      res.push_back(c);
    }
    return res;
  }
}
