// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

bool matching(char a, char b) {
  if((a == '(') && b == ')') || (a == '{') && b == '}') || (a == '[') && b == ']')) {
    return true;
  }
  return false;
}

bool isValid(string s) {
  stack<int> result;
  for(int i = 0; i < s.length(); i++) {
    if(s[i] == '{' || s[i] == '[' || s[i] == '(') {
      result.push(s[i]);
    } else {
      if(result.empty()) {
        return false;
      }
      if(matching(result.top(), s[i])) {
        result.pop();
      } else {
        return false;
      }
    }
  }

  if(result.empty()) { return true; }
  else { return false; }
}
