/* There are 8 prison cells in a row, and each cell is either occupied or vacant.

Each day, whether the cell is occupied or vacant changes according to the following rules:
>> If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
>> Otherwise, it becomes vacant.

(Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.)

We describe the current state of the prison in the following way: cells[i] == 1 if the i-th cell is occupied, else cells[i] == 0.

Given the initial state of the prison, return the state of the prison after N days (and N such changes described above.)

Example 1:
Input: cells = [0,1,0,1,1,0,0,1], N = 7
Output: [0,0,1,1,0,0,0,0]
Explanation:
The following table summarizes the state of the prison on each day:
Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
Day 7: [0, 0, 1, 1, 0, 0, 0, 0]

Example 2:
Input: cells = [1,0,0,1,0,0,1,0], N = 1000000000
Output: [0,0,1,1,1,1,1,0] */

vector<int> toVector(int x) {
    vector<int> ans;
    for (int i = 0; i < 8; ++i)
        ans.push_back(!(x & (1 << i)));
    return ans;
}

vector<int> prisonAfterNDays(vector<int>& cells, int N) {
    vector<int> cache(512), v(1);
    int x = 0, id = 1;
    for (int i = 0; i < cells.size(); ++i)
        x ^= (!cells[i] << i);
    while (true) {
        v.push_back(x);
        cache[x] = id++;
        int y = ((x ^ (x << 2)) >> 1) & 255;
        x = y | 129;
        --N;
        if (cache[x] || N == 0) break;
    }
    if (N == 0) return toVector(x);
    int r = N % (id - cache[x]);
    return toVector(v[cache[x] + r]);
}
