// Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

/* Example 1:
Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".

Example 2:
Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".

Example 3:
Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".

Example 4:
Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b". */

bool backspaceCompare(string S, string T) {
  int i = S.length() - 1, j = T.length() - 1;
  while (1) {
      for (int back = 0; i >= 0 && (back || S[i] == '#'); --i)
          back += S[i] == '#' ? 1 : -1;
      for (int back = 0; j >= 0 && (back || T[j] == '#'); --j)
          back += T[j] == '#' ? 1 : -1;
      if (i >= 0 && j >= 0 && S[i] == T[j])
          i--, j--;
      else
          return i == -1 && j == -1;
  }
}
