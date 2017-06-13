/* A message containing letters from A-Z is being encoded to numbers using the following mapping:
'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example, given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2. */

/* Analysis:
The key to this problem is : num(current) = num(current-1) + num(current-2).
Be careful with the conditions of above equation:
+ if the current char =='0'
+ if the current char and previous char >26
+ if the previous char =='0' */

class Solution {
public:
    bool valid(string s){
        if (s.size() == 0){
          return false;
        }
        if (s[0] == '0'){
          return false;
        }
        if (s.size() == 2){
            if (s[0] > '2' || (s[0] == '2' && s[1] > '6')){
              return false;
            }
        }
        return true;
    }

    int numDecodings(string s) {
        if (s.empty()){
          return 0;
        }
        vector<int> res(s.size(), 0);
        if (s[0] != '0'){
          res[0] = 1; // set res[0]
        }
        if (s.size() == 1){
          return res[0];
        }
        if (valid(s.substr(0,2))){
          res[1]++; //set res[1]
        }
        if (s[0]!='0' && s[1]!='0'){
          res[1]++; //set res[1]
        }

        //DP
        for (int i = 2; i < s.size(); i++){
            if (s[i] != '0'){
              res[i] += res[i - 1];
            }
            if (valid(s.substr(i - 1,2))){
                res[i] += res[i - 2];
            }
        }

        return res[s.size() - 1];
    }
};
