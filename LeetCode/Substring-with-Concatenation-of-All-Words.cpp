// You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

/* Example 1:

Input:
  s = "barfoothefoobarman",
  words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.

Example 2:

Input:
  s = "wordgoodstudentgoodword",
  words = ["word","student"]
Output: [] */

vector<int> findSubstring(string s, vector<string>& words) {
  vector<int> ans;
  if(words.empty())return ans;

  //record the number of each word
  map<string,int> hash;
  for(int i = 0; i < words.size(); ++i)
      ++hash[words[i]];

  //get the word len
  int len = words[0].size();

  //start the loop
  for(int i = 0; i < s.size(); ++i){
      int cnt = 1;
      map<string,int> temp = hash;

      //the word is in the hash, -- means use one time
      if((i + len <= s.size()) && temp[s.substr(i, len)]--){
          while((i + cnt * len) < s.size()){
              //if the word is used out also break
              if(temp[s.substr(i + cnt * len, len)]--)
                  ++cnt;
              else
                  break;
          }
          if(cnt == words.size()) ans.push_back(i);
      }
  }
  return ans;
}
