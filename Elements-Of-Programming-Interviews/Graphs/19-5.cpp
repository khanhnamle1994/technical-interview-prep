// Consider a vertex type for a directed graph in which there are two fields: an integer label and a list of references to other vertices.
// Design an algorithm that takes a reference to a vertex u, and creates a copy of the graph on the vertices reachable from u. Return the
// copy of u.

/* Solution:
We traverse the graph starting from u. Each time we encounter a vertex or an edge that is not yet in the clone, we add it to the clone. We
recognize new vertices by maintaining a hash table mapping vertices in the original graph to their counterparts in the new graph. Any standard
graph traversal algorithm works - this code uses BFS. */

struct GraphVertex {
  int label;
  vector<GraphVertex*> edges;
};

GraphVertex* CloneGraph(GraphVertex* G) {
  if(!G) {
    return nullptr;
  }

  unordered_map<GraphVertex*, GraphVertex*> vertex_map;
  queue<GraphVertex*> q;
  q.emplace(G);
  vertex_map.emplace(G, new GraphVertex({G->label}));
  while(!q.empty()) {
    auto v = q.front();
    q.pop();
    for(GraphVertex* e : v->edges) {
      // Try to copy vertex e
      if(vertex_map.find(e) == vertex_map.end()) {
        vertex_map.emplace(e, new GraphVertex({e->label}));
        q.emplace(e);
      }
      // Copy edge v->e
      vertex_map[v]->edges.emplace_back(vertex_map[e]);
    }
  }
  return vertex_map[G];
}

// The space complexity is O(|V| + |E|), which is the space taken by the result
