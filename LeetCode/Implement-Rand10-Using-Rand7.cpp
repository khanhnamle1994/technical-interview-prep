/* Given a function rand7 which generates a uniform random integer in the range 1 to 7, write a function rand10 which generates a uniform random integer in the range 1 to 10.

Do NOT use system's Math.random().

Example 1:
Input: 1
Output: [7]

Example 2:
Input: 2
Output: [8,4]

Example 3:
Input: 3
Output: [8,1,10] */

stack<int> cache;

int rand10() {
    while (cache.size() == 0) generate();
    int res = cache.top(); cache.pop();
    return res;
}

void generate() {
    int n = 19;
    long cur = 0, range = long(pow(7, n));
    for (int i = 0; i < n; ++i) cur += long(pow(7, i)) * (rand7() - 1);
    while (cur < range / 10 * 10) {
        cache.push(cur % 10 + 1);
        cur /= 10;
        range /= 10;
    }
}
