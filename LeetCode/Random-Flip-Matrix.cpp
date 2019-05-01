/* You are given the number of rows n_rows and number of columns n_cols of a 2D binary matrix where all values are initially 0. Write a function flip which chooses a 0 value uniformly at random, changes it to 1, and then returns the position [row.id, col.id] of that value. Also, write a function reset which sets all values back to 0. Try to minimize the number of calls to system's Math.random() and optimize the time and space complexity.

Example 1:
Input:
["Solution","flip","flip","flip","flip"]
[[2,3],[],[],[],[]]
Output: [null,[0,1],[1,2],[1,0],[1,1]]

Example 2:
Input:
["Solution","flip","flip","reset","flip"]
[[1,2],[],[],[],[]]
Output: [null,[0,0],[0,1],null,[0,0]] */

int m,n;
unordered_set<int> flag;

Solution(int n_rows, int n_cols):m(n_rows),n(n_cols),flag() {

}

vector<int> flip() {
    int index = rand()%(m*n);
    while (flag.find(index) !=  flag.end())
        index = rand()%(m*n);
    flag.insert(index);
    return vector<int>{index/n,index%n};
}

void reset() {
  flag.clear();
}
