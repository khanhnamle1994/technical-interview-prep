/* Given an undirected graph, return true if and only if it is bipartite.

Recall that a graph is bipartite if we can split it's set of nodes into two independent subsets A and B such that every edge in the graph has one node in A and another node in B.

The graph is given in the following form: graph[i] is a list of indexes j for which the edge between nodes i and j exists.  Each node is an integer between 0 and graph.length - 1.  There are no self edges or parallel edges: graph[i] does not contain i, and it doesn't contain any element twice.

Example 1:
Input: [[1,3], [0,2], [1,3], [0,2]]
Output: true
Explanation:
The graph looks like this:
0----1
|    |
|    |
3----2
We can divide the vertices into two groups: {0, 2} and {1, 3}.

Example 2:
Input: [[1,2,3], [0,2], [0,1,3], [0,2]]
Output: false
Explanation:
The graph looks like this:
0----1
| \  |
|  \ |
3----2
We cannot find a way to divide the set of nodes into two independent subsets. */

class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;
public:
    DisjointSet(int n) {
        parent = vector<int>(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        rank = vector<int>(n, 1);
    }

    int findSet(int p) {
        int t = p;
        while (t != parent[t])
            t = parent[t];
        parent[p] = t;
        return t;
    }

    void unionSets(int a, int b) {
        int setA = findSet(a), setB = findSet(b);
        if (setA == setB)
            return;
        if (rank[setA] < rank[setB])
            swap(setA, setB);
        rank[setA] += rank[setB];
        parent[setB] = setA;
    }
};

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    if (!n)
        return 0;
    DisjointSet ds(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            if (ds.findSet(i) == ds.findSet(graph[i][j]))
                return 0;
            if (j)
                ds.unionSets(graph[i][j], graph[i][j - 1]);
        }
    }
    return 1;
}
