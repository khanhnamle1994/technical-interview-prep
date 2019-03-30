/* Given a binary string S (a string consisting only of '0' and '1's) and a positive integer N, return true if and only if for every integer X from 1 to N, the binary representation of X is a substring of S.

Example 1:
Input: S = "0110", N = 3
Output: true

Example 2:
Input: S = "0110", N = 4
Output: false */

bool queryString(string S, int N) {
    /// Transfer the target N into binary representation, store that in tar.
    string tar;
    int tmp = N;
    while(tmp){
        tar.insert(tar.begin(), tmp%2 + '0') ;
        tmp >>= 1;
    }

    /// nums records all <= N distinct numbers that covered by S .
    /// For example, 55 = "110101"
    /// "110101" will store in nums if N >= 55, else do nothing if N < 55.
    /// Use Set to avoid duplication.
    /// since 1 <= N <= 10^9, the binary reprersentation of N cannot be longer than 30.
    unordered_set<string> nums;

    for(int i = 0; i < S.size(); i++){
        /// leading 0 is not consiered - starting with 1.
        if( S[i] == '0') continue;

        /// check the sub-string of S starting from i, with length up to 30.
        for(int len = 1; len <= 30 && i + len - 1 < S.size(); len++){
            string subS = S.substr(i, len);
            /// compare the binary representation with our target N
            /// If it's larger than N already, we can stop.
            if( subS.size() > tar.size() ||  (subS.size() == tar.size() && subS > tar)) break;

		/// subS is covered, record it at the corresponding index len-1
            nums.insert(subS);
        }
    }

    // Check if all numbers <= N are covered as a substring of tar.
    return nums.size() == N;
}
