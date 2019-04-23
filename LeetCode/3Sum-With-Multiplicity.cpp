/* Given an integer array A, and an integer target, return the number of tuples i, j, k  such that i < j < k and A[i] + A[j] + A[k] == target.

As the answer can be very large, return it modulo 10^9 + 7.

Example 1:
Input: A = [1,1,2,2,3,3,4,4,5,5], target = 8
Output: 20
Explanation:
Enumerating by the values (A[i], A[j], A[k]):
(1, 2, 5) occurs 8 times;
(1, 3, 4) occurs 8 times;
(2, 2, 4) occurs 2 times;
(2, 3, 3) occurs 2 times.

Example 2:
Input: A = [1,1,2,2,2,2], target = 5
Output: 12
Explanation:
A[i] = 1, A[j] = A[k] = 2 occurs 12 times:
We choose one 1 from [1,1] in 2 ways,
and two 2s from [2,2,2,2] in 6 ways. */

int threeSumMulti(vector<int>& A, int target) {
    unordered_map<int, long> c;
    for (int a : A) c[a]++;
    long res = 0;
    for (auto it : c)
        for (auto it2 : c) {
            int i = it.first, j = it2.first, k = target - i - j;
            if (!c.count(k)) continue;
            if (i == j && j == k)
                res += c[i] * (c[i] - 1) * (c[i] - 2) / 6;
            else if (i == j && j != k)
                res += c[i] * (c[i] - 1) / 2 * c[k];
            else if (i < j && j < k)
                res += c[i] * c[j] * c[k];
        }
    return res % int(1e9 + 7);
}
