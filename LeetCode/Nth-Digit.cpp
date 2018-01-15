// Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

/* Example 1:
Input:
3
Output:
3

Example 2:
Input:
11
Output:
0

Explanation:
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10. */

int findNthDigit(int n) {
  long long multiplier = 9,digits = 1,begin = 1;
  while(n > multiplier * digits) {
      n -= multiplier * digits++;
      multiplier *= 10;
  }
  int after = (n - 1) / digits, location = (n - 1) % digits;
  begin = pow(10,(digits - 1));
  string a = (to_string(begin + after));
  a = a[location];
  return stoi(a);
}

// My code is done by following step:
// 1. to calculate how many digits the number has and the beginning of the corresponding digits number such as 10,100,1000.
// 2. to find how many numbers after the beginning number.
// 3. find the location of digit that we want.
