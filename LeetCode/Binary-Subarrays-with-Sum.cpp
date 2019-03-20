/* In an array A of 0s and 1s, how many non-empty subarrays have sum S?

Example 1:

Input: A = [1,0,1,0,1], S = 2
Output: 4

Explanation:
The 4 subarrays are bolded below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1] */

int numSubarraysWithSum(vector<int>& A, int S) {
    int l = 0, r = 0, tl = 0, cnt = 0;
    for (r=0;r<A.size();r++) {
        S -= A[r];
        while (l < r && S < 0) S += A[l++];
        if(S == 0) cnt++;
        tl = l;
        while(tl < r && (A[tl] == 0 || S < 0)) {
            S -= A[tl++];
            if (S == 0) cnt++;
        }
    }
    return cnt;
}
