// X is a good number if after rotating each digit individually by 180 degrees, we get a valid number that is different from X.  Each digit must be rotated - we cannot choose to leave it alone.

// A number is valid if each digit remains a digit after rotation. 0, 1, and 8 rotate to themselves; 2 and 5 rotate to each other; 6 and 9 rotate to each other, and the rest of the numbers do not rotate to any other number and become invalid.

// Now given a positive number N, how many numbers X from 1 to N are good?

/* Example:
Input: 10
Output: 4
Explanation:
There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
Note that 1 and 10 are not good numbers, since they remain unchanged after rotating. */

int rotatedDigits(int N) {
  int f[] = {1,1,2,0,0,2,2,0,1,2};
  int res = 0;
  for(int i = 1; i <= N; i++){
      int p = i;
      int s = 1;
      while(p){
          s *= f[p%10];
          p /= 10;
      }
      if(s >=2) res+=1;
  }
  return res;
}
