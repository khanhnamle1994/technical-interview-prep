/* There are n cities connected by m flights. Each fight starts from city u and arrives at v with a price w.

Now given all the cities and flights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.

Example 1:
Input:
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 1
Output: 200

Example 2:
Input:
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 0
Output: 500 */

void dfs(int src, int dst, int k, int cost, vector<int>& visited, int& ans, unordered_map<int, vector<pair<int,int>>>& g ) {
      if (src == dst) { ans = cost; return; }
      if (k == 0) return;
      visited[src]=1;
      for (const auto& x : g[src]) {
        if (visited[x.first]==0){
            if (cost + x.second > ans) continue; // IMPORTANT!!! prunning

            dfs(x.first, dst, k - 1, cost + x.second, visited, ans, g);

        }
      }
      visited[src] = 0;
}

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
  unordered_map<int, vector<pair<int,int>>> g;
  for (const auto& e : flights)
      g[e[0]].emplace_back(e[1], e[2]);
  int ans = INT_MAX;
  vector<int> visited(n,0);
  dfs(src, dst, K + 1, 0, visited, ans, g);
  return ans == INT_MAX ? - 1 : ans;
}
