/* Given a string S of digits, such as S = "123456579", we can split it into a Fibonacci-like sequence [123, 456, 579].

Formally, a Fibonacci-like sequence is a list F of non-negative integers such that:
>> 0 <= F[i] <= 2^31 - 1, (that is, each integer fits a 32-bit signed integer type);
>> F.length >= 3;
>> and F[i] + F[i+1] = F[i+2] for all 0 <= i < F.length - 2.

Also, note that when splitting the string into pieces, each piece must not have extra leading zeroes, except if the piece is the number 0 itself.

Return any Fibonacci-like sequence split from S, or return [] if it cannot be done.

Example 1:
Input: "123456579"
Output: [123,456,579]

Example 2:
Input: "11235813"
Output: [1,1,2,3,5,8,13]

Example 3:
Input: "112358130"
Output: []
Explanation: The task is impossible.

Example 4:
Input: "0123"
Output: []
Explanation: Leading zeroes are not allowed, so "01", "2", "3" is not valid.

Example 5:
Input: "1101111"
Output: [110, 1, 111]
Explanation: The output [11, 0, 11, 11] would also be accepted. */

bool isFabo(vector<int>& path, int num){
    int n = path.size();
    return n<2 || (n >= 2 && num - path[n-1] == path[n-2]);
}

void dfs(vector<int>& ret, vector<int>& path, string& S, int start){
    if(!ret.empty()) return;
    if(start == S.size()){
        if (path.size()>=3) ret = path;
        return;
    }
    long val = 0;
    for(int i = start; i<S.size(); i++){
        val = 10*val + S[i]-'0';
        if(val > INT_MAX) return;
        if(isFabo(path, (int)val)){
            path.push_back(val);
            dfs(ret, path, S, i+1);
            path.pop_back();
        }
        if(val == 0) return;
    }
}

vector<int> splitIntoFibonacci(string S) {
    vector<int> ret;
    vector<int> path;
    dfs(ret, path, S, 0);
    return ret;
}
