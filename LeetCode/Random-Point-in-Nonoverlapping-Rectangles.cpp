/* Given a list of non-overlapping axis-aligned rectangles rects, write a function pick which randomly and uniformily picks an integer point in the space covered by the rectangles.

Example 1:
Input:
["Solution","pick","pick","pick"]
[[[[1,1,5,5]]],[],[],[]]
Output:
[null,[4,1],[4,1],[3,3]]

Example 2:
Input:
["Solution","pick","pick","pick","pick","pick"]
[[[[-2,-2,-1,-1],[1,0,3,0]]],[],[],[],[],[]]
Output:
[null,[-1,-2],[2,0],[-2,-1],[3,0],[-2,-2]]

Explanation of Input Syntax:
The input is two lists: the subroutines called and their arguments. Solution's constructor has one argument, the array of rectangles rects. pick has no arguments. Arguments are always wrapped with a list, even if there aren't any. */

vector<int> areas;
int max_area;
vector<vector<int>> rects;

Solution(vector<vector<int>> rects) {
    this->rects = rects;
    max_area = 0;
    areas.push_back(0);
    for (auto& r : rects) {
        max_area += (r[2]-r[0]+1) * (r[3]-r[1]+1);
        areas.push_back(max_area);
    }
}

vector<int> pick() {
    vector<int> ans;
    int r = rand() % max_area;
    auto itor = upper_bound(areas.begin(), areas.end(), r);
    int idx = itor - areas.begin() - 1;
    const auto& rect = rects[idx];
    return {rect[0]+rand()%(rect[2]-rect[0]+1), rect[1]+rand()%(rect[3]-rect[1]+1)};
}
