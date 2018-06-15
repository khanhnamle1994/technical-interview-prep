// You have n super washing machines on a line. Initially, each washing machine has some dresses or is empty.

// For each move, you could choose any m (1 ≤ m ≤ n) washing machines, and pass one dress of each washing machine to one of its adjacent washing machines at the same time .

// Given an integer array representing the number of dresses in each washing machine from left to right on the line, you should find the minimum number of moves to make all the washing machines have the same number of dresses. If it is not possible to do it, return -1.

/* Example1

Input: [1,0,5]

Output: 3

Explanation:
1st move:    1     0 <-- 5    =>    1     1     4
2nd move:    1 <-- 1 <-- 4    =>    2     1     3
3rd move:    2     1 <-- 3    =>    2     2     2
Example2

Input: [0,3,0]

Output: 2

Explanation:
1st move:    0 <-- 3     0    =>    1     2     0
2nd move:    1     2 --> 0    =>    1     1     1
Example3

Input: [0,2,0]

Output: -1

Explanation:
It's impossible to make all the three washing machines have the same number of dresses. */

int findMinMoves(vector<int>& machines) {
  int len = machines.size();
  vector<int> sum(len + 1, 0);
  for (int i = 0; i < len; ++i)
      sum[i + 1] = sum[i] + machines[i];

  if (sum[len] % len) return -1;

  int avg = sum[len] / len;
  int res = 0;
  for (int i = 0; i < len; ++i)
  {
      int l = i * avg - sum[i];
      int r = (len - i - 1) * avg - (sum[len] - sum[i] - machines[i]);

      if (l > 0 && r > 0)
          res = std::max(res, std::abs(l) + std::abs(r));
      else
          res = std::max(res, std::max(std::abs(l), std::abs(r)));
  }
  return res;
}
