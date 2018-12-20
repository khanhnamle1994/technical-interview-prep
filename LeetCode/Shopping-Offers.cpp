/* In LeetCode Store, there are some kinds of items to sell. Each item has a price.

However, there are some special offers, and a special offer consists of one or more different kinds of items with a sale price.

You are given the each item's price, a set of special offers, and the number we need to buy for each item. The job is to output the lowest price you have to pay for exactly certain items as given, where you could make optimal use of the special offers.

Each special offer is represented in the form of an array, the last number represents the price you need to pay for this special offer, other numbers represents how many specific items you could get if you buy this offer.

You could use any of special offers as many times as you want.

Example 1:
Input: [2,5], [[3,0,5],[1,2,10]], [3,2]
Output: 14
Explanation:
There are two kinds of items, A and B. Their prices are $2 and $5 respectively.
In special offer 1, you can pay $5 for 3A and 0B
In special offer 2, you can pay $10 for 1A and 2B.
You need to buy 3A and 2B, so you may pay $10 for 1A and 2B (special offer #2), and $4 for 2A.

Example 2:
Input: [2,3,4], [[1,1,0,4],[2,2,1,9]], [1,2,1]
Output: 11
Explanation:
The price of A is $2, and $3 for B, $4 for C.
You may pay $4 for 1A and 1B, and $9 for 2A ,2B and 1C.
You need to buy 1A ,2B and 1C, so you may pay $4 for 1A and 1B (special offer #1), and $3 for 1B, $4 for 1C.
You cannot add more items, though only $9 for 2A ,2B and 1C. */

int helper(vector<int>& price, vector<vector<int>>& special, unordered_map<int, int>& mp, int k) {
    if (mp.count(k)) return mp[k];
    int n = price.size(), ans = 0;
    // pows is to help get each digit of key
    vector<int> pows(n, 1);
    for (int i = n-2; i >= 0; i--) pows[i] = pows[i+1]*10;
    for (int i = 0; i < n; i++) ans += ((k/pows[i])%10)*price[i];
    for (auto spe:special) {
        int key = 0, i = 0;
        // check whether this offer is valid
        while (i < n) {
            int t = (k/pows[i])%10;
            if (t >= spe[i])
                key = key*10+(t-spe[i++]);
            else
                break;
        }
        if (i == n) ans = min(ans, spe[n]+helper(price, special, mp, key));
    }
    mp[k] = ans;
    return ans;
}
int get_key(vector<int>& needs) {
    int n = needs.size(), key = 0;
    for (int i = n-1, p = 1; i >= 0; i--, p *= 10)
        key += needs[i]*p;
    return key;
}

int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
    // memorize intermediate results
    unordered_map<int, int> mp;
    return helper(price, special, mp, get_key(needs));
}
