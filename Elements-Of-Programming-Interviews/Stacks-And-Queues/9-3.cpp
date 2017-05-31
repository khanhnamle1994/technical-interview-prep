// Write a program that tests if a string made up of the characters '(', ')', '[', ']', '{' and '}' is well-formed.

/* Solution:
Let's begin with well-formed strings consisting solely of left and right parentheses. If such a string is well-formed, each right parenthesis
must match the closest left parenthesis to its left. Therefore, starting from the left, every time we see a left parenthesis, we store it.
Each time we see a right parenthesis, we match it with a stored left parenthesis. Since there are not brackets or braces, we can simply
keep a count of the number of unmatched left parentheses.

For the general case, we do the same, except that we need to explicitly store unmatched left characters. We cannot use 3 counters, because
that will not tell us the last unmatched one. A stack is a perfect option for this application: we use it to record the unmatched left
characters, with the most recent one at the top.

If we encounter a right character and the stack is empty or the top of the stack is a different type of left character, the right character
is not matched, implying the string is not matched. If all characters have been processed and the stack is nonempty, there are unmatched
left characters so the string is not matched. */

bool IsWellFormed(const string& s) {
  stack<char> left_chars;
  for(int i = 0; i < s.size(); i++) {
    if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
      left_chars.emplace(s[i]);
    } else {
      if(left_chars.empty()) {
        return false; // unmatched right character
      }
      if((s[i] == ')' && left_chars.top() != '(') || (s[i] == '}' && left_chars.top() != '{') || (s[i] == ']' && left_chars.top() != '[')){
        return false;
      }
      left_chars.pop();
    }
  }
  return left_chars.empty();
}

// The time complexity is O(n) since for each character we perform O(1) operations.
