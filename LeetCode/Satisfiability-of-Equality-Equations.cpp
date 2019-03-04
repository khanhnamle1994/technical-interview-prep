/* Given an array equations of strings that represent relationships between variables, each string equations[i] has length 4 and takes one of two different forms: "a==b" or "a!=b".  Here, a and b are lowercase letters (not necessarily different) that represent one-letter variable names.

Return true if and only if it is possible to assign integers to variable names so as to satisfy all the given equations.

Example 1:
Input: ["a==b","b!=a"]
Output: false
Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.  There is no way to assign the variables to satisfy both equations.

Example 2:
Input: ["b==a","a==b"]
Output: true
Explanation: We could assign a = 1 and b = 1 to satisfy both equations.

Example 3:
Input: ["a==b","b==c","a==c"]
Output: true

Example 4:
Input: ["a==b","b!=c","c==a"]
Output: false

Example 5:
Input: ["c==c","b==d","x!=z"]
Output: true */

int findRoot(vector<int>& disjointSet, int i) {
    if (disjointSet[i] == -1)
        return i;
    return (disjointSet[i] = findRoot(disjointSet,disjointSet[i]));
}

void combine(vector<int>& disjointSet, vector<int>& setSize, int i, int j) {
    if (i == j) return;
    i = findRoot(disjointSet,i);
    j = findRoot(disjointSet,j);
    if (i == j) return;
    if (setSize[i] < setSize[j]) {
        setSize[i] += setSize[j];
        disjointSet[j] = i;
    }
    else {
        setSize[j] += setSize[i];
        disjointSet[i] = j;
    }
}

bool test(vector<int>& disjointSet, int i, int j) {
    i = findRoot(disjointSet,i);
    j = findRoot(disjointSet,j);
    return (i != j);
}

bool equationsPossible(vector<string>& equations) {
    int size = equations.size();
    if (size < 2) return true;

    vector<int> disjointSet(26,-1), setSize(26,1);
    //for (int i = 0; i < 26; ++i) cout << disjointSet[i] << ' '; cout << endl;
    //for (int i = 0; i < 26; ++i) cout << setSize[i] << ' '; cout << endl;
    for (int i = 0; i < size; ++i)
        if (equations[i][1] == '=')
            combine(disjointSet,setSize,equations[i][0]-'a',equations[i][3]-'a');
    //for (int i = 0; i < 26; ++i) cout << disjointSet[i] << ' '; cout << endl;
    //for (int i = 0; i < 26; ++i) cout << setSize[i] << ' '; cout << endl;
    for (int i = 0; i < size; ++i)
        if (equations[i][1] == '!')
            if (!test(disjointSet,equations[i][0]-'a',equations[i][3]-'a'))
                return false;
    return true;
}
