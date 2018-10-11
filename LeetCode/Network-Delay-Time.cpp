// There are N network nodes, labelled 1 to N.

// Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.

// Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.

int networkDelayTime(vector<vector<int>>& times, int N, int K) {
  vector<int> dist(N + 1, INT_MAX);
  dist[K] = 0;
  for (int i = 0; i < N; i++) {
      for (vector<int> e : times) {
          int u = e[0], v = e[1], w = e[2];
          if (dist[u] != INT_MAX && dist[v] > dist[u] + w) {
              dist[v] = dist[u] + w;
          }
      }
  }

  int maxwait = 0;
  for (int i = 1; i <= N; i++)
      maxwait = max(maxwait, dist[i]);
  return maxwait == INT_MAX ? -1 : maxwait;
}
