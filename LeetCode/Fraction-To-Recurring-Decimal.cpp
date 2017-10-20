// Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
// If the fractional part is repeating, enclose the repeating part in parentheses.

// For example,
// Given numerator = 1, denominator = 2, return "0.5".
// Given numerator = 2, denominator = 1, return "2".
// Given numerator = 2, denominator = 3, return "0.(6)".

string fractionToDecimal(int numerator, int denominator) {
  if (!numerator)
    return "0";
  string res;
  if (numerator < 0 ^ denominator < 0)
    res += '-';

  long numer = numerator < 0 ? (long)numerator * (-1) : (long)numerator;
  long denom = denominator < 0 ? (long)denominator * (-1) : (long)denominator;
  long integral = numer / denom;

  res += to_string(integral);
  long rmd = numer % denom;

  if (!rmd)
    return res;
  res += '.';
  rmd *= 10;
  unordered_map<long, long> mp;

  while (rmd) {
      long quotient = rmd / denom;
      if (mp.find(rmd) != mp.end()) {
          res.insert(mp[rmd], 1, '(');
          res += ')';
          break;
      }
      mp[rmd] = res.size();
      res += to_string(quotient);
      rmd = (rmd % denom) * 10;
  }
  return res;
}

// Well, the key to this problem is on how to identify the recurring parts. After doing some examples using pen and paper,
// you may find that for the decimal parts to recur, the remainders should recur. So we need to maintain the remainders we have seen.
// Once we see a repeated remainder, we know that we have reached the end of the recurring parts and should enclose it with a ).
// However, we still need to insert the ( to the correct position. So we maintain a mapping from each remainder to the position of the
// corresponding quotient digit of it in the recurring parts. Then we use this mapping to retrieve the starting position of the recurring
// parts.

// Now we have solved the trickiest part of this problem.

// There are some remaining problems to solve to achieve a bug-free solution.
// 1. Pay attention to the sign of the result;
// 2. Handle cases that may cause overflow like numerator = -2147483648, denominator = -1 appropriately by using long long;
// 3. Handle all the cases of (1) no fractional part; (2) fractional part does not recur; and (3) fractional part recurs respectively.

// To handle problem 3, we divide the division process into the integral part and the fractional part. For the fractional part, if it does
// not recur, then the remainder will become 0 at some point and we could return. If it does recur, the method metioned in the first
// paragraph has already handled it.

// Taking all these into considerations, we have the following code, which takes 0 ms :-)
