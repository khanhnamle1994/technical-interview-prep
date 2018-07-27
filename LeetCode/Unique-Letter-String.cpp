/* A character is unique in string S if it occurs exactly once in it.
For example, in string S = "LETTER", the only unique characters are "L" and "R".
Let's define UNIQ(S) as the number of unique characters in string S.
For example, UNIQ("LETTER") =  2.
Given a string S with only uppercases, calculate the sum of UNIQ(substring) over all non-empty substrings of S.
If there are two or more equal substrings at different positions in S, we consider them different.
Since the answer can be very large, return the answer modulo 10 ^ 9 + 7. */

/* Example 1:

Input: "ABC"
Output: 10
Explanation: All possible substrings are: "A","B","C","AB","BC" and "ABC".
Evey substring is composed with only unique letters.
Sum of lengths of all substring is 1 + 1 + 1 + 2 + 2 + 3 = 10

Example 2:

Input: "ABA"
Output: 8
Explanation: The same as example 1, except uni("ABA") = 1. */

#define MOD 1000000007

int uniqueLetterString(string S) {
  pair<int, int> last_pos[26];
	for (int i = 0; i < 26; ++i)
	{
		last_pos[i].first = last_pos[i].second = -1;
	}

	long long ret = 0, last_calc = 0;
	int len = S.length();
	for (int i = 0; i < len; ++i)
	{
		int j = S[i] - 'A', offset = 0;
		pair<int, int>& pos = last_pos[j];
		if (pos.first == -1 && pos.second == -1) // letter s[i] first occur, such as AB, now C
		{
			offset = i + 1;
		}
		else
		{
			if (pos.first == -1) // letter s[i] occur once, such as ABC, now A
			{
				offset = i - pos.second - (pos.second + 1);
			}
			else // letter s[i] occur more then once, such as ABCAC now A .only calculate until we reach the prev prev s[i]
			{
				offset = i - pos.second - (pos.second - pos.first);
			}
			pos.first = pos.second;
		}
		last_calc = (last_calc + offset) % MOD;
		ret = (ret + last_calc) % MOD;
		pos.second = i;
	}
	return ret;
}
