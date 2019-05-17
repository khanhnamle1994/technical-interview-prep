/* Given a positive integer K, you need find the smallest positive integer N such that N is divisible by K, and N only contains the digit 1.

Return the length of N.  If there is no such N, return -1.

Example 1:
Input: 1
Output: 1
Explanation: The smallest answer is N = 1, which has length 1.

Example 2:
Input: 2
Output: -1
Explanation: There is no such positive integer N divisible by 2.

Example 3:
Input: 3
Output: 3
Explanation: The smallest answer is N = 111, which has length 3. */

int smallestRepunitDivByK(int K) {
    if (K % 2 == 0 || K % 5 == 0) {
        return -1;
    }
    long long digit = 1;
    for (int i = 1; ;i++) {
        if (digit % K == 0) {
            return i;
        }
        digit = (digit * 10 + 1) % K;
    }
}
