/* Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

If possible, output any possible result.  If not possible, return the empty string.

Example 1:
Input: S = "aab"
Output: "aba"

Example 2:
Input: S = "aaab"
Output: "" */

string reorganizeString(string S) {
    vector<int> mp(26);
    int n = S.size();
    for (char c: S)
        ++mp[c-'a'];
    priority_queue<pair<int, char>> pq;
    for (int i = 0; i < 26; ++i) {
        if (mp[i] > (n+1)/2) return "";
        if (mp[i]) pq.push({mp[i], i+'a'});
    }
    queue<pair<int, char>> myq;
    string ans;
    while (!pq.empty() || myq.size() > 1) {
        if (myq.size() > 1) {
            auto cur = myq.front();
            myq.pop();
            if (cur.first != 0) pq.push(cur);
        }
        if (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            ans += cur.second;
            cur.first--;
            myq.push(cur);
        }
    }
    return ans;
}
