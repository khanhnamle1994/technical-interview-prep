/* Given several boxes with different colors represented by different positive numbers.

You may experience several rounds to remove boxes until there is no box left. Each time you can choose some continuous boxes with the same color (composed of k boxes, k >= 1), remove them and get k*k points.

Find the maximum points you can get.

Example 1:
Input:
[1, 3, 2, 2, 2, 3, 4, 3, 1]

Output:
23

Explanation:
[1, 3, 2, 2, 2, 3, 4, 3, 1]
----> [1, 3, 3, 4, 3, 1] (3*3=9 points)
----> [1, 3, 3, 3, 1] (1*1=1 points)
----> [1, 1] (3*3=9 points)
----> [] (2*2=4 points) */

int removeBoxes(vector<int>& boxes) {
    vector<int> A, f; // f: frequency
    for(int i=1,count=1; i<=boxes.size(); ++i){
        if(boxes[i] != boxes[i - 1]||i==boxes.size())
            A.push_back(boxes[i-1]), f.push_back(count),count=1;
        else count++;
    }


    int dp[100][100][100] = {0};

    function<int(int, int , int)> dfs =[&](int i, int j, int k){
        if (i > j) return 0;
         if (dp[i][j][k]) return dp[i][j][k];
        dp[i][j][k] = dfs(i, j - 1, 0) + (f[j] + k) * (f[j] + k);
        for (int pos = i; pos < j; pos++) {
            if (A[pos] == A[j]) dp[i][j][k] = max(dp[i][j][k], dfs(i, pos, f[j] + k) + dfs(pos + 1, j - 1, 0));
        }
        return dp[i][j][k];
    };

    return dfs(0, A.size()-1, 0);
}
