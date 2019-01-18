/* Given an array w of positive integers, where w[i] describes the weight of index i, write a function pickIndex which randomly picks an index in proportion to its weight.

Note:
1 <= w.length <= 10000
1 <= w[i] <= 10^5
pickIndex will be called at most 10000 times.

Example 1:
Input:
["Solution","pickIndex"]
[[[1]],[]]
Output: [null,0]

Example 2:
Input:
["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
[[[1,3]],[],[],[],[],[]]
Output: [null,0,1,1,1,0] */

vector<int> s;

Solution(vector<int> w) {
    for (int i : w) s.push_back(s.empty() ? i : (i + s.back()));
}

int pickIndex() {
    int m = s.back();
    int r = rand() % m;
    auto it = upper_bound(s.begin(), s.end(), r);
    return it - s.begin();
}
