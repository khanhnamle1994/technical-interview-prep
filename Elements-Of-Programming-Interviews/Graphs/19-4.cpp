/* High performance database systems use multiple processes and resource locking. These systems may not provide mechanisms to avoid or
prevent deadlock: a situation in which two or more competing actions are each waiting for the other to finish, which precludes all these
actions from progressing. Such systems must support a mechanism to detec deadlocks, as well as an algorithm for recovering from them.

One deadlock detection algorithm makes use of a "wait-for" graph to track which other processes a process is currently blocking on. In a
wait-for graph, processes are represented as nodes, and an edge from process P to Q implies Q is holding a resource that P needs and thus
P is waiting for Q to release its lock on that resource. A cycle in this graph implies the possibility of a deadlock.

Write a program that takes as input a directed graph and checks if the graph contains a cycle. */

/* Solution:
We can check for the existence of a cycle in G by running DFS on G. Recall DFS maintians a color for each vertex. Initially, all vertices
are white. When a vertex is first discovered, it is colored gray. When DFS finishes processing a vertex, that vertex is colored black.

As soon as we discover an edge from a gray vertex back to a gray vertex, a cycle exists in G and we can stop. Conversely, if there exists a
cycle, once we first reach vertex in the cycle (call it v), we will visit its predecessor in the cycle (call it u) before finishing processing
v, i.e., we will find an edge from a gray to a gray vertex. In summary, a cycle exists if and only if DFS discovers an edge from a gray vertex
to a gray vertex. Since the graph may not be strongly connected, we must examine each vertex, and run DFS from it if it has not already been
explored. */

struct GraphVertex {
  enum Color { white, gray, black } color = white;
  vector<GraphVertex*> edges;
};

bool IsDeadlocked(vector<GraphVertex>* G) {
  return any_of(begin(*G), end(*G), [](GraphVertex& vertex) {
    return vertex.color == GraphVertex::white && HasCycle(&vertex);
  });
}

bool HasCycle(GraphVertex* cur) {
  // Visiting a gray vertex means a cycle
  if(cur->color == GraphVertex::gray) {
    return true;
  }

  cur->color = GraphVertex::gray; // Marks current vetex as a gray one
  // Traverses the neighbor vertices
  for(GraphVertex*& next : cur->edges) {
    if(next->color != GraphVertex::black) {
      if(HasCycle(next)) {
        return true;
      }
    }
  }
  cur->color = GraphVertex::black; // Marks current vertex as black
  return false;
}

// The time complexity of DFS is O(|V| + |E|): we iterate over all vertices, and spend a constant amount of time per edge. The space complexity
// is O(|V|), which is the maximum stack depth - if we go deeper than |V| calls, some vertex must repeat, implying a cycle in the graph,
// which leads to early termination.
