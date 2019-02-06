/* Given a set of points in the xy-plane, determine the minimum area of any rectangle formed from these points, with sides not necessarily parallel to the x and y axes.

If there isn't any rectangle, return 0. */

string getKey(int a, int b) {
    return to_string(a) + "_" + to_string(b);
}

double minAreaFreeRect(vector<vector<int>>& points) {
    unordered_set<string> us;
    for (auto &p: points) {
        us.insert(getKey(p[0], p[1]));
    }
    double ans = 0;
    for (int i = 0; i < points.size(); ++i) {
        for (int j = 0; j < points.size(); ++j) {
            for (int k = j + 1; k < points.size(); ++k) {
                if (i == j || i == k) continue;
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                int x3 = points[k][0], y3 = points[k][1];
                if ((x2 - x1) * (x3 - x1) + (y2 - y1) * (y3 - y1) != 0) continue;
                int x4 = x2 + x3 - x1, y4 = y2 + y3 - y1;
                if (us.count(getKey(x4, y4))) {
                    double w = pow(pow(x2 - x1, 2) + pow(y2 - y1, 2), 0.5);
                    double l = pow(pow(x3 - x1, 2) + pow(y3 - y1, 2), 0.5);
                    double area = w * l;
                    if (ans == 0 || area != 0 && area < ans) {
                        ans = area;
                    }
                }
            }
        }
    }
    return ans;
}
