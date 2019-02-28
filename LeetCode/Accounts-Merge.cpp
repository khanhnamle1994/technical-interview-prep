/* Given a list accounts, each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some email that is common to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

Example 1:

Input:
accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]

Output: [["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]

Explanation:
The first and third John's are the same person as they have the common email "johnsmith@mail.com".
The second John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'],
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted. */

string find(string s, map<string, string>& p) {
    return p[s] == s ? s : find(p[s], p);
}

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    map<string, string> owner;
    map<string, string> parents;
    map<string, set<string>> unions;
    for (int i = 0; i < accounts.size(); i++) {
        for (int j = 1; j < accounts[i].size(); j++) {
            parents[accounts[i][j]] = accounts[i][j];
            owner[accounts[i][j]] = accounts[i][0];
        }
    }
    for (int i = 0; i < accounts.size(); i++) {
        string p = find(accounts[i][1], parents);
        for (int j = 2; j < accounts[i].size(); j++)
            parents[find(accounts[i][j], parents)] = p;
    }
    for (int i = 0; i < accounts.size(); i++)
        for (int j = 1; j < accounts[i].size(); j++)
            unions[find(accounts[i][j], parents)].insert(accounts[i][j]);

    vector<vector<string>> res;
    for (pair<string, set<string>> p : unions) {
        vector<string> emails(p.second.begin(), p.second.end());
        emails.insert(emails.begin(), owner[p.first]);
        res.push_back(emails);
    }
    return res;
}
