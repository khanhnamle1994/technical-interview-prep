/* Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.

Each person may dislike some other people, and they should not go into the same group.

Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

Return true if and only if it is possible to split everyone into two groups in this way.

Example 1:
Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]

Example 2:
Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false

Example 3:
Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false */

bool dfs(vector<vector<int>> &graph, vector<int> &colors, int idx, int cc) {
    if(colors[idx] != 0) return colors[idx] == cc;
    colors[idx] = cc;

    for(int nidx : graph[idx]) {
        if(!dfs(graph, colors, nidx, -cc)) return false;
    }
    return true;
}

bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
    vector<vector<int>> graph(N);
    for(vector<int> d : dislikes) {
        graph[d[0]-1].push_back(d[1]-1);
        graph[d[1]-1].push_back(d[0]-1);
    }

    vector<int> colors(N);
    for(int i = 0; i < N; i++) {
        if(colors[i] == 0 && !dfs(graph, colors, i, 1)) return false;
    }

    return true;
}
