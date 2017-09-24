/* Additive number is a string whose digits can form additive sequence.

A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the
sequence must be the sum of the preceding two.

For example:
"112358" is an additive number because the digits can form an additive sequence: 1, 1, 2, 3, 5, 8.
1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8

"199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.
1 + 99 = 100, 99 + 100 = 199

Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.

Given a string containing only digits '0'-'9', write a function to determine if it's an additive number. */

bool checkEQ(string a, string b, string c){
  if (a.size() < b.size()) {
    a.swap(b);
  }

  if (c.size() - a.size() > 2){
    return false;
  }

  if ((a[0] == '0' && a.size() > 1) || (b[0] == '0' && b.size() > 1)){
    return false;
  }

  int i = a.size() - 1;
  int j = b.size() - 1;
  string s = "";
  int carry = 0;

  while (j >= 0) {
    int tmp = ( int(a[i]-char('0')) + int(b[j]-char('0')) + carry );
    s.insert(0, 1, char(tmp % 10 + '0'));
    carry = tmp / 10;
    i--;
    j--;
  }

  while (i >= 0) {
    int tmp = (int(a[i]-char('0')) + carry );
    s.insert(0, 1, char(tmp % 10 + '0'));
    carry = tmp / 10;
    i--;
  }

  if (carry > 0) {
    s = "1" + s;
  };

  return s.compare(c)==0;
}

void search(string prev1, string prev2, string num, bool& res){
  if (res == true) { return; }
  if (num == "") {
    res = true;
  } else {
    int sz = num.size();
    if (prev1 == "") {
      for (int i = 1; i <= sz - 2; i++){
        prev1 = num.substr(0, i);
        search(prev1, prev2, num.substr(i),res);
      }
    }

    if (prev2 == "") {
      for (int i = 1; i <= sz - 1; i++){
        prev2 = num.substr(0, i);
        search(prev1, prev2, num.substr(i),res);
      }
    }

    for (int i = 1; i <= sz; i++){
      if (checkEQ(prev1, prev2, num.substr(0,i)) == true){
        search(prev2, num.substr(0,i), num.substr(i),res);
      }
    }
  }
}

bool isAdditiveNumber(string num) {
  string prev1 = "";
  string prev2 = "";
  bool res = false;
  search(prev1, prev2, num, res);
  return res;
}

/* Analysis:
For this question, the first thing we could handle is: How to determine the sum of two strings in int is equal to the other string in int?

I use the string manipulation to handle the case when the number is too larger to be stored in an long long type (in cpp). This is
implemented in the checkEQ function shown in my code below. Note that, the question is not allowed to use "03", "02", ect format,
we also have to eliminte such cases (by the if condition in Line 6 below). In my implementation, the swap operation is to make the
longer number always stores in a. The Line 5 is to ignore the check if the two numbers a and c are totally different, regarding to the
fact that the sum of two numbers will not exceede the max length of two numbers + 1.
E.g., a = 998, b = 80, c = a + b = 998 + 80 = 1078

The length of c will never be greater than length of a + 1, since the carry will never greater than 1. Using this properties of sum operation,
we could easily implement the following code for checking the sum of three strings as shown in checkEQ function. DO NOT forget to check the last carry!

Next we are facing the main part of the problem: find a way to check the whole string. I will show how I handle this in a clear way (which may not be
optimal but quite easy to understand).

From the problem we know that:
+ The length of each number could be different.
+ At least we should have 3 numbers, which forms the whole string.
+ If we find one match (a + b = c), we shall keep searching (b + c = ???)
+ If our search goes to the end of the number, we could return True.

These observations tell us that:
+ We could check each possible length of each number
+ The max length of first number is length of string - 2, the max length of second number is length of string - length of 1st number - 1.
+ We could use a recursion to do this search, since every time, the procedure is almost same, but the input data are different.
+ The termination condition of our recursion is whether we match the whole string.
*/
