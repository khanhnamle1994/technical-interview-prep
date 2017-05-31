// Write a program that takes an arithmetical expression in RPN and returns the number that the expression evaluates to.

/* Solution:
Let's begin with the RPN example "3, 4, +, 2, *, 1, +". The ordinary form for this is (3 + 4) * 2 + 1. To evaluate this by hand, we would
scan from left to right. We record 3, then 4, then applying the + to 3 and 4, and record the result, 7. Note that we never need to examine
the 3 and 4 again. Next we multiply by 2, and record the result, 14. Finally, we add 1 to obtain the final result, 15.

Observe that we need to record partial results, and as we encounter operators, we apply them to the partial results. The partial results are
added and removed in last-in, first-out order, which makes a stack the natural data structure for evaluating RPN expressions */

int Eval(const string& RPN_expression) {
  stack<int> intermediate_results;
  stringstream ss(RPN_expression);
  string token;
  const char kDelimiter = ',';

  while(getline(ss, token, kDelimiter)) {
    if(token == "+" || token == "-" || token == "*" || token == "/") {
      const int y = intermediate_results.top();
      intermediate_results.pop();
      const int x = intermediate_results.top();
      intermediate_results.pop();
      switch(token.froint()) {
        case '+':
          intermediate_results.emplace(x+y);
          break;
        case '-':
          intermediate_results.emplace(x-y);
          break;
        case '*':
          intermediate_results.emplace(x*y);
          break;
        case '/':
          intermediate_results.emplace(x/y);
          break;
      }
    } else { // token is a number
      intermediate_results.emplace(stoi(token));
    }
  }
  return intermediate_results.top();
}

// Since we perform O(1) computation per character of the string, the time complexity is O(n), where n is the length of the string.
