/* Given an array of integers A with even length, return true if and only if it is possible to reorder it such that A[2 * i + 1] = 2 * A[2 * i] for every 0 <= i < len(A) / 2.

Example 1:
Input: [3,1,3,6]
Output: false

Example 2:
Input: [2,1,2,6]
Output: false

Example 3:
Input: [4,-2,2,-4]
Output: true
Explanation: We can take two groups, [-2,-4] and [2,4] to form [-2,-4,2,4] or [2,4,-2,-4].

Example 4:
Input: [1,2,4,16,8,4]
Output: false */

bool canReorderDoubled(vector<int>& A) {
    unordered_map<int, int> c;
    for (int a : A) c[a]++;
    vector<int> keys;
    for (auto it : c)
        keys.push_back(it.first);
    sort(keys.begin(), keys.end(), [](int i, int j) {return abs(i) < abs(j);});
    for (int x : keys) {
        if (c[x] > c[2 * x])
            return false;
        c[2 * x] -= c[x];
    }
    return true;
}
