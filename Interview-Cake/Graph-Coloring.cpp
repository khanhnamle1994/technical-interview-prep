// Given an undirected graph with maximum degree D, find a graph coloring using at most D+1 colors.

// Graphs are represented by a list of NN node objects, each with a label, a set of neighbors, and a color:
class GraphNode:

    def __init__(self, label):
        self.label = label
        self.neighbors = set()
        self.color = None

a = GraphNode('a')
b = GraphNode('b')
c = GraphNode('c')

a.neighbors.add(b)
b.neighbors.add(a)
b.neighbors.add(c)
c.neighbors.add(b)

graph = [a, b, c]

// Solution
// We go through the nodes in one pass, assigning each node the first legal color we find.

// How can we be sure we'll always have at least one legal color for every node? In a graph with maximum degree D, each node has at most D neighbors. That means there are at most D colors taken by a node's neighbors. And we have D+1 colors, so there's always at least one color left to use.

// When we color each node, we're careful to stop iterating over colors as soon as we find a legal color.
void colorGraph(const vector<GraphNode*>& graph, const vector<string>& colors)
{
    for (auto node : graph) {
        const auto& neighbors = node->getNeighbors();

        if (neighbors.find(node) != neighbors.end()) {
            ostringstream errorMessage;
            errorMessage << "Legal coloring impossible for node with loop: "
                    << node->getLabel();
            throw invalid_argument(errorMessage.str());
        }

        // get the node's neighbors' colors, as a set so we
        // can check if a color is illegal in constant time
        unordered_set<string> illegalColors;
        for (const auto neighbor : neighbors) {
            if (neighbor->hasColor()) {
                illegalColors.insert(neighbor->getColor());
            }
        }

        // assign the first legal color
        for (const auto& color : colors) {
            if (illegalColors.find(color) == illegalColors.cend()) {
                node->setColor(color);
                break;
            }
        }
    }
}

// Complexity
// O(N+M) time where N is the number of nodes and M is the number of edges.

// The runtime might not look linear because we have outer and inner loops. The trick is to look at each step and think of things in terms of the total number of edges (M) wherever we can:

// >> We check if each node appears in its own unordered set of neighbors. Checking if something is in an unordered set is O(1), so doing it for all N nodes is O(N).
// >> When we get the illegal colors for each node, we iterate through that node's neighbors. So in total, we cross each of the graphs MM edges twice: once for the node on either end of each edge. O(M) time.
// >> When we assign a color to each node, we're careful to stop checking colors as soon as we find one that works. In the worst case, we'll have to check one more color than the total number of neighbors. Again, each edge in the graph adds two neighbors—one for the node on either end—so there are 2*M neighbors. So, in total, we'll have to try O(N+M) colors.

// Putting all the steps together, our complexity is O(N+M).

// What about space complexity? The only thing we're storing is the illegalColors unordered set. In the worst case, all the neighbors of a node with the maximum degree (D) have different colors, so our unordered set takes up O(D) space.
