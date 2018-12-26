/* Given a set of points in the xy-plane, determine the minimum area of a rectangle formed from these points, with sides parallel to the x and y axes.

If there isn't any rectangle, return 0.

Example 1:
Input: [[1,1],[1,3],[3,1],[3,3],[2,2]]
Output: 4

Example 2:
Input: [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
Output: 2 */

int minAreaRect(vector<vector<int>>& points) {
    int area = INT_MAX;

    // vector of diagonal points
    vector<pair<vector<int>, vector<int>>> d;
    std::set<vector<int>> m;

    // Hash all the points in m
    for (auto p : points) {
        m.insert(p);
    }

    // Check each two points that can form a diagonal
    for (int i = 0; i < points.size(); i++) {
        vector<int> p = points[i];
        for (int j = i + 1; j < points.size(); j++) {
            vector<int> q = points[j];
            // If x of p and q or y of p and q are different
            if (p[0] != q[0] && p[1] != q[1] &&
                // and if the points on the other diagonal exist
                m.find({ p[0], q[1] }) != m.end() &&
                m.find({ q[0], p[1] }) != m.end()) {
                // Calculate the area
                area = std::min(area,
                                std::abs(p[0] - q[0]) *
                                        std::abs(p[1] - q[1]));
            }
        }
    }
    return area == INT_MAX ? 0 : area;
}
