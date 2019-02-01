/* Sometimes people repeat letters to represent extra feeling, such as "hello" -> "heeellooo", "hi" -> "hiiii".  Here, we have groups, of adjacent letters that are all the same character, and adjacent characters to the group are different.  A group is extended if that group is length 3 or more, so "e" and "o" would be extended in the first example, and "i" would be extended in the second example.  As another example, the groups of "abbcccaaaa" would be "a", "bb", "ccc", and "aaaa"; and "ccc" and "aaaa" are the extended groups of that string.

For some given string S, a query word is stretchy if it can be made to be equal to S by extending some groups.  Formally, we are allowed to repeatedly choose a group (as defined above) of characters c, and add some number of the same character c to it so that the length of the group is 3 or more.  Note that we cannot extend a group of size one like "h" to a group of size two like "hh" - all extensions must leave the group extended - ie., at least 3 characters long.

Given a list of query words, return the number of words that are stretchy.

Example:
Input:
S = "heeellooo"
words = ["hello", "hi", "helo"]
Output: 1

Explanation:
We can extend "e" and "o" in the word "hello" to get "heeellooo".
We can't extend "helo" to get "heeellooo" because the group "ll" is not extended. */

bool check(string S, string W) {
    int n = S.size(), m = W.size(), j = 0;
    for (int i = 0; i < n; i++)
        if (j < m && S[i] == W[j]) j++;
        else if (i > 1 && S[i - 2] == S[i - 1] && S[i - 1] == S[i]);
        else if (0 < i && i < n - 1 && S[i - 1] == S[i] && S[i] == S[i + 1]);
        else return false;
    return j == m;
}

int expressiveWords(string S, vector<string>& words) {
    int res = 0;
    for (auto &W : words) if (check(S, W)) res++;
    return res;
}
