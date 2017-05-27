// Implement string/integer inter-conversion functions

// Integer to string: add each computed digit to the end, and then reverse the computed sequence. If x is negative, we record that, negate
// x, and then add a '-' before reversing. If x is 0, our code breaks out of the iteration without writing any digits, in which case we
// need to explicitly set a 0

// To convert form a string to an integer: begin from the leftmost digit and with each succeeding digit, multiply the partial result by 10
// and add that digit. For example, to convert "314" to an integer, we initialize the partial result r to 0. In the 1st iteration, r = 3,
// in the 2nd iteration, r = 3 * 10 + 1 = 31, and in the 3rd iteration, r = 31 * 10 + 4 = 314, which is the final result.

// Negative numbers are handled by recording the sign and negating the result. 

string IntToString(int x) {
  bool is_negative = false;
  if (x < 0) {
    is_negative = true;
  }

  string s;
  do {
    s += '0' + abs(x % 10);
    x /= 10;
  } while (x);

  if (is_negative) {
    s += '-'; // adds the negative sign back
  }
  return {s.rbegin(), s.rend()};
}

int StringToInt(const string& s) {
  int result = 0;
  for (int i = s[0] == '-' ? 1 : 0; i < s.size(); i++) {
    const int digit = s[i] - '0';
    result = result * 10 + digit;
  }
  return s[0] == '-' ? -result : result;
}
