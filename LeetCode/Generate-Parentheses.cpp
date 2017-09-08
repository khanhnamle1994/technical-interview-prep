// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

vector<string> generateParenthesis(int n) {
  vector<string> res;
  addingpar(res, "", n, 0);
  return res;
}

void addingpar(vector<string> &v, string str, int n, int m) {
  if(n == 0 && m == 0) {
    v.push_back(str);
    return;
  }

  if(m > 0) {
    addingpar(v, str+")", n, m - 1);
  }

  if(n > 0) {
    addingpar(v, str+"(", n - 1, m + 1);
  }
}
