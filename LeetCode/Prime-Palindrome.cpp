/* Find the smallest prime palindrome greater than or equal to N.

Recall that a number is prime if it's only divisors are 1 and itself, and it is greater than 1.

For example, 2,3,5,7,11 and 13 are primes.

Recall that a number is a palindrome if it reads the same from left to right as it does from right to left.

For example, 12321 is a palindrome.

Example 1:
Input: 6
Output: 7

Example 2:
Input: 8
Output: 11

Example 3:
Input: 13
Output: 101 */

bool isPrime(int num) {
    if (num < 2 || num % 2 == 0) return num == 2;
    for (int i = 3; i * i <= num; i += 2)
        if (num % i == 0) return false;
    return true;
}

int primePalindrome(int N) {
    if (8 <= N && N <= 11) return 11;
    for (int x = 1; x < 100000; ++x) {
        string s = to_string(x), r(s.rbegin(), s.rend());
        int y = stoi(s + r.substr(1));
        if (y >= N && isPrime(y)) return y;
    }
    return -1;
}
