// There are a total of n courses you have to take, labeled from 0 to n - 1.
// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
// Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
// There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

/* For example:
2, [[1,0]]
There are a total of 2 courses to take.
To take course 1 you should have finished course 0. So the correct course order is [0,1]

4, [[1,0],[2,0],[3,1],[3,2]]
There are a total of 4 courses to take.
To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3]. */

vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
  vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
  vector<int> degrees = compute_indegree(graph);
  queue<int> zeros;
  for (int i = 0; i < numCourses; i++)
      if (!degrees[i]) zeros.push(i);
  vector<int> toposort;
  for (int i = 0; i < numCourses; i++) {
      if (zeros.empty()) return {};
      int zero = zeros.front();
      zeros.pop();
      toposort.push_back(zero);
      for (int neigh : graph[zero]) {
          if (!--degrees[neigh])
              zeros.push(neigh);
      }
  }
  return toposort;
}

vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<unordered_set<int>> graph(numCourses);
    for (auto pre : prerequisites)
        graph[pre.second].insert(pre.first);
    return graph;
}

vector<int> compute_indegree(vector<unordered_set<int>>& graph) {
    vector<int> degrees(graph.size(), 0);
    for (auto neighbors : graph)
        for (int neigh : neighbors)
            degrees[neigh]++;
    return degrees;
}
