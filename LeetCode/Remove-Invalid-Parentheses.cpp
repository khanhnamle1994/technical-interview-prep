// Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.
/* Examples:
"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""] */

void remove(int open, int left, int right, int iStart, string s, vector<string> &out) {
    // Iterate through all the remaining characters and see if we can remove them
    // In the meantime we can also keep track of how many open parantheses we have
    // so far to avoid calculating it separately.
    for (int i = iStart; i < s.size() && open >= 0; ++i) {
        if (s[i] == '(') {
            // If we should remove this open parantheses, make sure last element wasn't an
            // open parantheses since removing this would result in the same output
            // as removing the previous one so it's redundant.
            if (left > 0 && (i == 0 || s[i - 1] != '('))
                remove(open, left - 1, right, i, s.substr(0, i) + s.substr(i + 1), out);

            ++open;
        } else if (s[i] == ')') {
            // Same as open parantheses, don't remove if same as previous character
            if (right > 0 && (i == 0 || s[i - 1] != ')'))
                remove(open, left, right - 1, i, s.substr(0, i) + s.substr(i + 1), out);

            --open;
        }
    }

    if (left == 0 && right == 0 && open == 0)
        out.emplace_back(move(s));
}

vector<string> removeInvalidParentheses(string s) {
    vector<string> out;

    // How many left and right parantheses should we remove?
    int left = 0, right = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            ++left;
        } else if (s[i] == ')') {
            if (left > 0)
                --left;
            else
                ++right;
        }
    }

    remove(0, left, right, 0, s, out);
    return out;
}

/*
If there are repeated open/close parentheses only remove one of them
If the current state will not yield a solution (number of open parentheses so far < 0) stop iterating
Remember open parentheses count so we don't have to calculate it again */
