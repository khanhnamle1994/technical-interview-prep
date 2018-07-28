// You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

// The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

/* Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3

Example 2:

Input: J = "z", S = "ZZ"
Output: 0 */

/* Explanation
1 - read J and build jewels hash set.
2 - read S and count jewels.

Time complexity:
I used hash set and it's O(1) to check if it contains an element. So the total time complexity will be O(M+N), instead of O(MN) */

int numJewelsInStones(string J, string S) {
  int res = 0;
  unordered_set<char> setJ(J.begin(), J.end());
  for (char s : S) if (setJ.count(s)) res++;
  return res;
}
