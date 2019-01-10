/* We are given two arrays A and B of words.  Each word is a string of lowercase letters.

Now, say that word b is a subset of word a if every letter in b occurs in a, including multiplicity.  For example, "wrr" is a subset of "warrior", but is not a subset of "world".

Now say a word a from A is universal if for every b in B, b is a subset of a.

Return a list of all universal words in A.  You can return the words in any order.

Example 1:
Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["e","o"]
Output: ["facebook","google","leetcode"]

Example 2:
Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["l","e"]
Output: ["apple","google","leetcode"]

Example 3:
Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["e","oo"]
Output: ["facebook","google"]

Example 4:
Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["lo","eo"]
Output: ["google","leetcode"]

Example 5:
Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["ec","oc","ceo"]
Output: ["facebook","leetcode"] */

vector<int> counter(string& word) {
    vector<int> count(26);
    for (char c : word) count[c - 'a']++;
    return count;
}

vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
    vector<int> uni(26), tmp(26);
    int i;
    for (string b : B) {
        tmp = counter(b);
        for (i = 0; i < 26; ++i)
            uni[i] = max(uni[i], tmp[i]);
    }
    vector<string> res;
    for (string a : A) {
        tmp = counter(a);
        for (i = 0; i < 26; ++i)
            if (tmp[i] < uni[i]) break;
        if (i == 26) res.push_back(a);
    }
    return res;
}
