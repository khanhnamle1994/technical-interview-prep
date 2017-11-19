// Implement a basic calculator to evaluate a simple expression string.
// The expression string contains only non-negative integers, +, -, *, / operators and empty spaces.
// The integer division should truncate toward zero.
// You may assume that the given expression is always valid.

/* Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5 */

/* Analysis:
This is a straightforward question that only requires basic string operations.
Note that, there is no brackets "(" or ")" in the string, there is no negative numbers in the string.
All we have is a string with +, -, *, / and numbers, and spaces.

Note that, the numbers in the string is not constrained to be 0 to 9, in other words, the first step
is to split those numbers and operators from the string.  We can keep every digits of the number in a
temporary string, until meet one of the operators. Then convert the number string into int and save it,
don't forget to reset the tmp string.

Now we have a list of numbers as well as a list of operators. Since * and / operations have higher priorities,
and there is no "( )", we can first compute those operations using the two adjacent numbers. After all the
* and / operations are "removed" from the list, the last step is to compute all the remaining + and - in its
original order.

Finally, the first number in the number list is the result.
*/

int calculate(string s) {
  vector<int> num;  //vector of ints
  vector<char> ops; //vector of operators

  //Convert string into ints and operators
  string n = ""; // string to store digits
  stringstream ss;
  for (int i = 0; i < s.size(); i++) {
      if (s[i] == ' ') {
          continue; //remove spaces
      } else {
          if (s[i] >= '0' && s[i] <= '9'){
              n = n + s[i];
          } else {
              ss.clear();
              ss << n;
              int tmp;
              ss >> tmp;
              num.push_back(tmp);
              n = "";
              ops.push_back(s[i]);
          }
      }
  }
  //don't forget the last number
  if (n.size() != 0) {
      ss.clear();
      ss << n;
      int tmp;
      ss >> tmp;
      num.push_back(tmp);
  }


  //compute all the * and / operations
  int i = 0;
  while (i < ops.size()) {
      if (ops[i] == '*'){
          num[i] = num[i] * num[i + 1];
          num.erase(num.begin() + i + 1);
          ops.erase(ops.begin() + i);
      } else if (ops[i] == '/') {
          num[i] = num[i] / num[i + 1];
          num.erase(num.begin() + i + 1);
          ops.erase(ops.begin() + i);
      } else {
          i++;
      }
  }

  //compute all the + and - operations
  i = 0;
  while (i < ops.size()){
      if (ops[i] == '+'){
          num[i] = num[i] + num[i + 1];
          num.erase(num.begin() + i + 1);
          ops.erase(ops.begin() + i);
      } else if (ops[i] == '-'){
          num[i] = num[i] - num[i + 1];
          num.erase(num.begin() + i + 1);
          ops.erase(ops.begin() + i);
      } else {
          i++;
      }
  }

  return num[0];
}
