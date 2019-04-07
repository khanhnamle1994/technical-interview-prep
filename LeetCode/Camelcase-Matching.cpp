/* A query word matches a given pattern if we can insert lowercase letters to the pattern word so that it equals the query. (We may insert each character at any position, and may insert 0 characters.)

Given a list of queries, and a pattern, return an answer list of booleans, where answer[i] is true if and only if queries[i] matches the pattern.

Example 1:
Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FB"
Output: [true,false,true,true,false]
Explanation:
"FooBar" can be generated like this "F" + "oo" + "B" + "ar".
"FootBall" can be generated like this "F" + "oot" + "B" + "all".
"FrameBuffer" can be generated like this "F" + "rame" + "B" + "uffer".

Example 2:
Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBa"
Output: [true,false,true,false,false]
Explanation:
"FooBar" can be generated like this "Fo" + "o" + "Ba" + "r".
"FootBall" can be generated like this "Fo" + "ot" + "Ba" + "ll".

Example 3:
Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBaT"
Output: [false,true,false,false,false]
Explanation:
"FooBarTest" can be generated like this "Fo" + "o" + "Ba" + "r" + "T" + "est". */

vector<bool> camelMatch(vector<string>& queries, string pattern) {
  vector<bool> ans(queries.size(),false);

  for(int i = 0;i<queries.size();i++){
      int patIdx = 0;
      int queIdx = 0;

      while(queIdx < queries[i].size() && patIdx < pattern.size()){
          if(queries[i][queIdx] == pattern[patIdx]){
              patIdx ++;
          }
	// if there is an uppercase letter appear in queries[i] but not in pattern, set the queIdx to the length of queries[i] to skip the while loop later.
          else if(queries[i][queIdx] <= 'Z' && queries[i][queIdx] >= 'A'){
              queIdx = queries[i].size();
              break;
          }
          queIdx++;
      }
      while(queIdx < queries[i].size()){
          if(queries[i][queIdx] <= 'Z' && queries[i][queIdx] >= 'A'){
              ans[i] = false;
              break;
          }
          queIdx ++;
      }
      ans[i] = (patIdx == pattern.size() && queIdx == queries[i].size());
  }

  return ans;
}
