/* A gene string can be represented by an 8-character long string, with choices from "A", "C", "G", "T".

Suppose we need to investigate about a mutation (mutation from "start" to "end"), where ONE mutation is defined as ONE single character changed in the gene string.

For example, "AACCGGTT" -> "AACCGGTA" is 1 mutation.

Also, there is a given gene "bank", which records all the valid gene mutations. A gene must be in the bank to make it a valid gene string.

Now, given 3 things - start, end, bank, your task is to determine what is the minimum number of mutations needed to mutate from "start" to "end". If there is no such a mutation, return -1.

Example 1:

start: "AACCGGTT"
end:   "AACCGGTA"
bank: ["AACCGGTA"]

return: 1

Example 2:

start: "AACCGGTT"
end:   "AAACGGTA"
bank: ["AACCGGTA", "AACCGCTA", "AAACGGTA"]

return: 2

Example 3:

start: "AAAAACCC"
end:   "AACCCCCC"
bank: ["AAAACCCC", "AAACCCCC", "AACCCCCC"]

return: 3 */

vector<string> addNextWords(string input, vector<string>& bank) {
    vector<string> ans;
    for(auto w: bank) {
        int cnt = 0;
        for(int i = 0;i < 8;i++) {
            if(w[i]!=input[i])
                cnt++;
            if(cnt >= 2)
                break;
        }
        if(cnt == 1)
            ans.push_back(w);
    }
    return ans;
}

int minMutation(string start, string end, vector<string>& bank) {
    set<string> b(bank.begin(), bank.end());

    if(bank.size() == 0 || !b.count(end))
        return -1;

    set<string> bq, eq;
    bq.insert(start);
    eq.insert(end);
    int bcnt = 0;
    int ecnt = 0;

    while(!bq.empty() && !eq.empty()) {
        if(bq.size() <= eq.size()) {
            set<string> temp;
            bcnt++;
            for(auto it = bq.begin();it!=bq.end();it++) {
                vector<string> edges = addNextWords(*it, bank);
                for(auto w: edges) {
                    if(eq.count(w))
                        return bcnt + ecnt;
                    temp.insert(w);
                }
            }
            bq = temp;

        } else {
            set<string> temp;
            ecnt++;
            for(auto it = eq.begin();it!=eq.end();it++) {
                vector<string> edges = addNextWords(*it, bank);
                for(auto w: edges) {
                    if(bq.count(w))
                        return bcnt + ecnt;
                    temp.insert(w);
                }
            }
            eq = temp;
        }
    }


    return -1;
}
