/* We have two types of tiles: a 2x1 domino shape, and an "L" tromino shape. These shapes may be rotated.

XX  <- domino

XX  <- "L" tromino
X

Given N, how many ways are there to tile a 2 x N board? Return your answer modulo 10^9 + 7.

(In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.)

Example:
Input: 3
Output: 5
Explanation:
The five different ways are listed below, different letters indicates different tiles:
XYZ XXZ XYY XXY XYY
XYZ YYZ XZZ XYY XXY */

int numTilings(int N) {
    if (N== 1) return 1; 
    vector<int> dpF(N, 0);
    vector<int> dpTL(N, 0);
    vector<int> dpBL(N, 0);
    int mod = 1E9+7;
    dpF[0] = 1;
    dpF[1] = 2; dpTL[1] = dpBL[1] = 1;
    for (int i = 2; i < N; i++) {
        dpF[i] = ((dpF[i-1]%mod + dpF[i-2]%mod)%mod + (dpTL[i-1]%mod + dpBL[i-1]%mod)%mod)%mod;
        dpTL[i] = (dpBL[i-1]%mod+dpF[i-2]%mod)%mod;
        dpBL[i] = (dpTL[i-1]%mod+dpF[i-2]%mod)%mod;
    }
    return dpF[N-1];
}
