// Evaluate the value of an arithmetic expression in Reverse Polish Notation.
// Valid operators are +, -, *, /. Each operand may be an integer or another expression.

// Examples:
// ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
// ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

/* Analysis:

This is a classical algorithm question. The polish notation is the similar to the postorder traversal of the binary tree,
and can be efficiently solved using the data structure-----stack.

The concept is:
When meeting the number, push into the stack.
When meeting the operator, pop the top 2 number and compute the value, then push the result back into the stack.
Until the end of the expression.
Output the top (last) value in the stack.

Details can be seen in the code below, there is some points need to be careful with, e.g. the order the the two numbers for
the operator.
*/

int evalRPN(vector<string>& tokens) {
  stack<int> st;
  string op = "+-*/"; // to check the operator

  if (tokens.size() == 0) { return 0; }
  for (int i = 0; i < tokens.size(); i++) {
    string tok = tokens[i];
    int o = op.find(tok); // operator number

    if (o != -1) {
      if (st.size() < 2) { return -1; }
      else {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        if (o == 0) { st.push(b + a);}
        if (o == 1) { st.push(b - a);}
        if (o == 2) { st.push(b * a);}
        if (o == 3) { st.push(b / a);}
      }
    } else {
      st.push(atoi(tok.c_str()));
    }
  }
  return st.top();
}
