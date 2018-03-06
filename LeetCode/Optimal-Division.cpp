// Given a list of positive integers, the adjacent integers will perform the float division. For example, [2,3,4] -> 2 / 3 / 4.

// However, you can add any number of parenthesis at any position to change the priority of operations. You should find out how to add parenthesis to get the maximum result, and return the corresponding expression in string format. Your expression should NOT contain redundant parenthesis.

/* Example:
Input: [1000,100,10,2]
Output: "1000/(100/10/2)"
Explanation:
1000/(100/10/2) = 1000/((100/10)/2) = 200
However, the bold parenthesis in "1000/((100/10)/2)" are redundant,
since they don't influence the operation priority. So you should return "1000/(100/10/2)".

Other cases:
1000/(100/10)/2 = 50
1000/(100/(10/2)) = 50
1000/100/10/2 = 0.5
1000/100/(10/2) = 2 */

string optimalDivision(vector<int>& nums) {
  int n = nums.size();
  string expr;
  for (int i = 0; i < n; i++) {
      if (i > 0) {
          expr += "/";
      }
      if (i == 1 && n > 2) {
          expr += "(";
      }
      expr += to_string(nums[i]);
      if (i == n - 1 && n > 2) {
          expr += ")";
      }
  }
  return expr;
}
