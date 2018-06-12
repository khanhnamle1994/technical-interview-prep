// Given an m x n matrix of positive integers representing the height of each unit cell in a 2D elevation map, compute the volume of water it is able to trap after raining.

/* Example:

Given the following 3x6 height map:
[
  [1,4,3,1,3,2],
  [3,2,1,3,2,4],
  [2,3,3,2,3,1]
]

Return 4. */

int i, j, val;

Pos (int i0, int j0, int v0) : i(i0), j(j0), val(v0){}
bool operator<(Pos const & to_less) const
{
    return val > to_less.val;
}

int trapRainWater(vector<vector<int>> const & heightMap) {
    priority_queue<Pos> que;
    int height = heightMap.size(), width = height > 0 ? heightMap.back().size() : 0;
    vector<vector<bool>> visited (height, vector<bool>(width, false));
    for (int i = 0; i < height; ++ i)
    {
        visited[i][0] = true, que.emplace(i, 0, heightMap[i][0]);
        if (width - 1 > 0)
            visited[i][width - 1] = true, que.emplace(i, width - 1, heightMap[i][width - 1]);
    }
    for (int j = 1; j < width - 1; ++ j)
    {
        visited[0][j] = true, que.emplace(0, j, heightMap[0][j]);
        if (height - 1 > 0)
            visited[height - 1][j] = true, que.emplace(height - 1, j, heightMap[height - 1][j]);
    }
    int sum = 0;
    while (que.size())
    {
        auto p = que.top(); que.pop();
        int i = p.i, j = p.j, waterLevel = p.val;
        sum += p.val - heightMap[i][j];
        if (i + 1 < height && !visited[i + 1][j])
            visited[i + 1][j] = true, que.emplace(i + 1, j, max(waterLevel, heightMap[i+1][j]));
        if (i - 1 >= 0 && !visited[i - 1][j])
            visited[i - 1][j] = true, que.emplace(i - 1, j, max(waterLevel, heightMap[i-1][j]));
        if (j + 1 < width && !visited[i][j + 1])
            visited[i][j + 1] = true, que.emplace(i, j + 1, max(waterLevel, heightMap[i][j+1]));
        if (j - 1 >= 0 && !visited[i][j - 1])
            visited[i][j - 1] = true, que.emplace(i, j - 1, max(waterLevel, heightMap[i][j-1]));
    }
    return sum;
}
