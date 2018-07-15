// An undirected, connected graph of N nodes (labeled 0, 1, 2, ..., N-1) is given as graph.

// graph.length = N, and j != i is in the list graph[i] exactly once, if and only if nodes i and j are connected.

// Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.

/* Example 1:

Input: [[1,2,3],[0],[0],[0]]
Output: 4
Explanation: One possible path is [1,0,2,0,3]

Example 2:

Input: [[1],[0,2,4],[1,3,4],[2],[1,2]]
Output: 4
Explanation: One possible path is [0,1,4,2,3] */

int dis[15][15];
int dp[1<<13][13];

void floyd(int n) {
    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
}
int DP(int n) {
    memset(dp, 0x3f, sizeof(dp));
    for (int i=0; i<n; i++)
        dp[1<<i][i] = 0;
    for (int group=1; group<(1<<n); group++)
        for (int u=0; u<n; u++)
            for (int v=0; v<n; v++) {
                int src = 1 << u, dst = 1 << v;
                if ((group & src) && !(group & dst))
                    dp[group|dst][v] = min(dp[group][u] + dis[u][v], dp[group|dst][v]);
            }
    int min_dis = 0x3f3f3f3f;
    for (int i=0; i<n; i++)
        min_dis = min(dp[(1<<n)-1][i], min_dis);
    return min_dis;
}

int shortestPathLength(vector<vector<int>>& graph) {
  int n = graph.size();
  memset(dis, 0x3f, sizeof(dis));
  for (int i=0; i<n; i++) {
      int to_size = graph[i].size();
      for (int j=0; j<to_size; j++) {
          int u = i, v = graph[i][j];
          dis[u][v] = 1;
      }
  }
  floyd(n);
  int min_dis = DP(n);
  return min_dis;
}

/* In my solution,
  dis[x][y] represents the minimun distance between node x and node y.
  dp[group][dst] represents the shortest distance that a man could walk through all nodes in the "group", and finally finished at the node "dst" ("dst" is one of the node in "group").

To calculate dp[][], enumerate every possible state (which is "group". For example, If group only has node 0 and node 2, the value of group is 101 in binary). Pick a node that is in the "group"(for example, node u), and pick a node that is not in the "group"(for example, node v). Then update dp[group+v][v] by getting the minimum value between dp[group+v][v] and dp[group][u] + dis[u][v]. */
