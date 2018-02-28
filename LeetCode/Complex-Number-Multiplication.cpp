// Given two strings representing two complex numbers.
// You need to return a string representing their multiplication. Note i^2 = -1 according to the definition.

/* Example 1:
Input: "1+1i", "1+1i"
Output: "0+2i"
Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.

Example 2:
Input: "1+-1i", "1+-1i"
Output: "0+-2i"
Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i. */

string complexNumberMultiply(string a, string b) {
  int ra, ia, rb, ib;
  char buff;
  stringstream aa(a), bb(b), ans;
  aa >> ra >> buff >> ia >> buff;
  bb >> rb >> buff >> ib >> buff;
  ans << ra*rb - ia*ib << "+" << ra*ib + rb*ia << "i";
  return ans.str();
}
