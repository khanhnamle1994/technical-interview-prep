// Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and return them in any order.

// The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.

/* Example:
Input: [[1,2], [3], [3], []]
Output: [[0,1,3],[0,2,3]]
Explanation: The graph looks like this:
0--->1
|    |
v    v
2--->3
There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3. */

void dfs(vector<vector<int>>& graph, vector<vector<int>>& res, vector<int> path, int cur) {
  path.push_back(cur);
  if (cur == graph.size() - 1) res.push_back(path);
  else for (auto it: graph[cur]) dfs(graph, res, path, it);
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
  vector<vector<int>> paths;
  vector<int> path;
  dfs(graph, paths, path, 0);
  return paths;
}
