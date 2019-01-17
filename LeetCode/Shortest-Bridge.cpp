/* In a given 2D binary array A, there are two islands.  (An island is a 4-directionally connected group of 1s not connected to any other 1s.)

Now, we may change 0s to 1s so as to connect the two islands together to form 1 island.

Return the smallest number of 0s that must be flipped.  (It is guaranteed that the answer is at least 1.)

Example 1:
Input: [[0,1],[1,0]]
Output: 1

Example 2:
Input: [[0,1,0],[0,0,0],[0,0,1]]
Output: 2

Example 3:
Input: [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
Output: 1 */

int abso(int n) {
    if (n<0) return -n;
    else return n;
}

void storePosition(const vector<vector<int>>& A, vector<vector<bool>>& check,
                 vector<pair<int,int>>& pos, int i, int j) {
    int m = A.size();
    int n = A[0].size();
    if (i>=0 && i<m && j>=0 && j<n && !check[i][j] && A[i][j]==1) {
        pair<int,int> p(i,j);
        pos.push_back(p);
        check[i][j] = true;

        storePosition(A, check, pos, i+1,j);
        storePosition(A, check, pos, i,j+1);
        storePosition(A, check, pos, i-1,j);
        storePosition(A, check, pos, i,j-1);
    }
}

int shortestBridge(vector<vector<int>>& A) {
    int m = A.size();
    int n = A[0].size();
    vector<vector<bool>> check(m, vector<bool>(n));
    vector<pair<int,int>> pos1;
    vector<pair<int,int>> pos2;
    bool first = true;

    for (int i = 0 ; i < m;i++){
        for (int j = 0; j< n;j++) {
            if (!check[i][j] && A[i][j]==1) {
                if(first) {
                    storePosition(A, check, pos1,i,j);
                    first = false;
                }else{
                    storePosition(A, check, pos2,i,j);
                }

            }
        }
    }
    int shortest = 200;
    for (int i = 0; i<pos1.size();i++){
        for (int j = 0; j < pos2.size();j++){
            int path = abso(pos1[i].first-pos2[j].first) + abso(pos1[i].second-pos2[j].second);
            shortest = min(shortest,path) ;
        }
    }

    return shortest-1;
}
