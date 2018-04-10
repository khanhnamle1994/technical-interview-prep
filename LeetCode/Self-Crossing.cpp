// You are given an array x of n positive numbers. You start at point (0,0) and moves x[0] metres to the north, then x[1] metres to the west, x[2] metres to the south, x[3] metres to the east and so on. In other words, after each move your direction changes counter-clockwise.

// Write a one-pass algorithm with O(1) extra space to determine, if your path crosses itself, or not.

/* Example 1:
Given x = [2, 1, 1, 2],
?????
?   ?
???????>
    ?

Return true (self crossing)

Example 2:
Given x = [1, 2, 3, 4],
????????
?      ?
?
?
?????????????>

Return false (not self crossing)

Example 3:
Given x = [1, 1, 1, 1],
?????
?   ?
?????>

Return true (self crossing) */

bool isSelfCrossing(vector<int>& x) {
  x.insert(x.begin(), 4, 0);

  int len = x.size();
  int i = 4;

  // outer spiral
  for (; i < len && x[i] > x[i - 2]; i++);

  if (i == len) return false;

  // check border
  if (x[i] >= x[i - 2] - x[i - 4])
  {
      x[i - 1] -= x[i - 3];
  }

  // inner spiral
  for (i++; i < len && x[i] < x[i - 2]; i++);

  return i != len;
}
