// Write an algorithm to determine if a number is "happy".
/* A happy number is a number defined by the following process:
Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the
number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process
ends in 1 are happy numbers. */

int digitSquareSum(int n) {
    int sum = 0, tmp;
    while (n) {
        tmp = n % 10;
        sum += tmp * tmp;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    int slow, fast;
    slow = fast = n;

    while(slow != fast) {
      slow = digitSquareSum(slow);
      fast = digitSquareSum(fast);
      fast = digitSquareSum(fast);
    }

    if (slow == 1)
      return 1;
    else
      return 0;
}
