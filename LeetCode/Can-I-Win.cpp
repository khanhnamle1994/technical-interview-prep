// In the "100 game," two players take turns adding, to a running total, any integer from 1..10. The player who first causes the running total to reach or exceed 100 wins.

// What if we change the game so that players cannot re-use integers?

// For example, two players might take turns drawing from a common pool of numbers of 1..15 without replacement until they reach a total >= 100.

// Given an integer maxChoosableInteger and another integer desiredTotal, determine if the first player to move can force a win, assuming both players play optimally.

// You can always assume that maxChoosableInteger will not be larger than 20 and desiredTotal will not be larger than 300.

/* Example

Input:
maxChoosableInteger = 10
desiredTotal = 11

Output:
false

Explanation:
No matter which integer the first player choose, the first player will lose.
The first player can choose an integer from 1 up to 10.
If the first player choose 1, the second player can only choose integers from 2 up to 10.
The second player will win by choosing 10 and get a total = 11, which is >= desiredTotal.
Same with other integers chosen by the first player, the second player will always win. */

int m[1<<20] = {}; // m[key]: memorized result when pool state = key

bool dfs(int maxChoosableInteger, int desiredTotal, int key) {
  if (desiredTotal <= 0 || m[key]) {
    return desiredTotal > 0 && m[key] > 0; // memorization or total reached by opponent
  }

  for (int i = 0; i < maxChoosableInteger; ++i) {
    if (!(key & 1 << i) && !dfs(maxChoosableInteger, desiredTotal - i - 1, key|1 << i)) {
      return m[key] = 1; // current player wins
    }
  }

  return !(m[key] = -1); // current player can't win
}

bool canIWin(int maxChoosableInteger, int desiredTotal) {
  int sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2; // sum of entire pool
  return desiredTotal < 2 ? true : sum < desiredTotal ? false : sum == desiredTotal ? maxChoosableInteger % 2 : dfs(maxChoosableInteger, desiredTotal, 0);
}
