/* Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

1 - Any left parenthesis '(' must have a corresponding right parenthesis ')'.
2 - Any right parenthesis ')' must have a corresponding left parenthesis '('.
3 - Left parenthesis '(' must go before the corresponding right parenthesis ')'.
4 - '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
5 - An empty string is also valid.

Example 1:
Input: "()"
Output: True

Example 2:
Input: "(*)"
Output: True

Example 3:
Input: "(*))"
Output: True */

bool checkValidString(string s) {
    int cmin = 0, cmax = 0;
    for (char c : s) {
        if (c == '(')
            cmax++, cmin++;
        if (c == ')')
            cmax--, cmin = max(cmin - 1, 0);
        if (c == '*')
            cmax++, cmin = max(cmin - 1, 0);
        if (cmax < 0) return false;
    }
    return cmin == 0;
}
