// You wrote a trendy new messaging app, MeshMessage, to get around flaky cell phone coverage.

// Instead of routing texts through cell towers, your app sends messages via the phones of nearby users, passing each message along
// from one phone to the next until it reaches the intended recipient. (Don't worry—the messages are encrypted while they're in transit.)

// Some friends have been using your service, and they're complaining that it takes a long time for messages to get delivered. After some
// preliminary debugging, you suspect messages might not be taking the most direct route from the sender to the recipient.

// Given information about active users on the network, find the shortest route for a message from one user (the sender) to another
// (the recipient). Return a vector of users that make up this route.

// Solution

// We treat the input user network as a graph in adjacency list format. Then we do a breadth-first search from the sender, stopping once
// we reach the recipient.

// In order to recover the actual shortest path from the sender to the recipient, we do two things:
// 1. during our breadth-first search, we keep track of how we reached each node, and
// 2. after our breadth-first search reaches the end node, we use our unordered map to backtrack from the recipient to the sender.

// To make sure our breadth-first search terminates, we're careful to avoid visiting any node twice. We could keep track of the nodes
// we've already seen in an unordered set, but, to save space, we reuse the unordered map we've already set up for recovering the path.

vector<string> reconstructPath(const unordered_map<string, string>& previousNodes,
                             const string& startNode, const string& endNode)
{
  vector<string> reversedShortestPath;

  // start from the end of the path and work backwards
  string currentNode = endNode;

  while (!currentNode.empty()) {
      reversedShortestPath.push_back(currentNode);
      currentNode = previousNodes.find(currentNode)->second;
  }

  // reverse our path to get the right order
  // by fliping it around, in place
  reverse(reversedShortestPath.begin(), reversedShortestPath.end());
  return reversedShortestPath;  // no longer reversed
}

vector<string> shortestPathBfs(const unordered_map<string, vector<string>>& graph,
                             const string& startNode, const string& endNode)
{
  if (graph.count(startNode) == 0) {
      throw invalid_argument("Start node not in graph");
  }
  if (graph.count(endNode) == 0) {
      throw invalid_argument("End node not in graph");
  }

  deque<string> nodesToVisit;
  nodesToVisit.push_back(startNode);

  // keep track of how we got to each node
  // we'll use this to reconstruct the shortest path at the end
  // we'll ALSO use this to keep track of which nodes we've
  // already visited
  unordered_map<string, string> howWeReachedNodes;
  howWeReachedNodes.emplace(startNode, "");

  while (!nodesToVisit.empty()) {
      string currentNode = move(nodesToVisit.front());
      nodesToVisit.pop_front();

      // stop when we reach the end node
      if (currentNode == endNode) {
          return reconstructPath(howWeReachedNodes, startNode, endNode);
      }

      for (const auto& neighbor : graph.find(currentNode)->second) {
          if (howWeReachedNodes.count(neighbor) == 0) {
              nodesToVisit.push_back(neighbor);
              howWeReachedNodes.emplace(neighbor, currentNode);
          }
      }
  }

  // if we get here, then we never found the end node
  // so there's NO path from startNode to endNode
  return vector<string>();
}

// Complexity

// Our solution has two main steps. First, we do a breadth-first search of the user network starting from the sender. Then, we use the
// results of our search to backtrack and find the shortest path.

// How much work is a breadth-first search?

// In the worst case, we'll go through the BFS loop once for every node in the graph, since we only ever add each node to nodesToVisit
// once (we check howWeReachedNodes to see if we've already added a node before). Each loop iteration involves a constant amount of work
// to dequeue the node and check if it's our end node. If we have n nodes, then this portion of the loop is O(N).

// But there's more to each loop iteration: we also look at the current node's neighbors. Over all of the nodes in the graph, checking
// the neighbors is O(M), since it involves crossing each edge twice: once for each node at either end.

// Putting this together, the complexity of the breadth-first search is O(N+M).

// What about backtracking to determine the shortest path? Handling each node in the path is O(1), and we could have at most N nodes in
// our shortest path. So, that's O(N) for building up the path. Then, it's another O(N) to reverse it. So, the total time complexity of
// our backtracking step is O(N).

// Putting these together, the time complexity of our entire algorithm is O(N+M).

// What about space complexity? The queue of nodes to visit, the mapping of nodes to previous nodes, and the final path ... they all
// store a constant amount of information per node. So, each data structure could take up to O(N) space if it stored information about
// all of our nodes. That means our overall space complexity is O(N).
