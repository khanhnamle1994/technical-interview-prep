/* In a warehouse, there is a row of barcodes, where the i-th barcode is barcodes[i].

Rearrange the barcodes so that no two adjacent barcodes are equal.  You may return any answer, and it is guaranteed an answer exists.

Example 1:
Input: [1,1,1,2,2,2]
Output: [2,1,2,1,2,1]

Example 2:
Input: [1,1,1,1,2,2,3,3]
Output: [1,3,1,3,2,1,2,1] */

vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    int pos = 0;
    unordered_map<int, int> m;
    set<pair<int, int>> s;
    for (auto n : barcodes) ++m[n];
    for (auto it = begin(m); it != end(m); ++it) s.insert({ it->second, it->first });
    for (auto it = s.rbegin(); it != s.rend(); ++it) {
      for (auto cnt = 0; cnt < it->first; ++cnt, pos += 2) {
        if (pos >= barcodes.size()) pos = 1;
        barcodes[pos] = it->second;
      }
    }
    return barcodes;
}
