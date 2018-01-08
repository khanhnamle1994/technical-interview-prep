// Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point
// number). Given some queries, return the answers. If the answer does not exist, return -1.0.

/* Example:
Given a / b = 2.0, b / c = 3.0.
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .
return [6.0, 0.5, -1.0, 1.0, -1.0 ].

The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size()
== values.size(), and the values are positive. This represents the equations. Return vector<double>.

According to the example above:
equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ].

The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction. */

struct Node {
    Node* parent;
    double value = 0.0;
    Node()  {parent = this;}
};

void unionNodes(Node* node1, Node* node2, double num, unordered_map<string, Node*>& map) {
    Node* parent1 = findParent(node1), *parent2 = findParent(node2);
    double ratio = node2 -> value * num / node1 -> value;
    for (auto it = map.begin(); it != map.end(); it ++)
        if (findParent(it -> second) == parent1)
            it -> second -> value *= ratio;
    parent1 -> parent = parent2;
}

Node* findParent(Node* node) {
    if (node -> parent == node)
        return node;
    node -> parent = findParent(node -> parent);
    return node -> parent;
}

vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
    unordered_map<string, Node*> map;
    vector<double> res;
    for (int i = 0; i < equations.size(); i ++) {
        string s1 = equations[i].first, s2 = equations[i].second;
        if (map.count(s1) == 0 && map.count(s2) == 0) {
            map[s1] = new Node();
            map[s2] = new Node();
            map[s1] -> value = values[i];
            map[s2] -> value = 1;
            map[s1] -> parent = map[s2];
        } else if (map.count(s1) == 0) {
            map[s1] = new Node();
            map[s1] -> value = map[s2] -> value * values[i];
            map[s1] -> parent = map[s2];
        } else if (map.count(s2) == 0) {
            map[s2] = new Node();
            map[s2] -> value = map[s1] -> value / values[i];
            map[s2] -> parent = map[s1];
        } else {
            unionNodes(map[s1], map[s2], values[i], map);
        }
    }

    for (auto query : queries) {
        if (map.count(query.first) == 0 || map.count(query.second) == 0 || findParent(map[query.first]) != findParent(map[query.second]))
            res.push_back(-1);
        else
            res.push_back(map[query.first] -> value / map[query.second] -> value);
    }
    return res;
}
