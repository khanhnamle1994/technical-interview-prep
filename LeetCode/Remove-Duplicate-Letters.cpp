// Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

/* Example:
Given "bcabc"
Return "abc"

Given "cbacdcbc"
Return "acdb" */

string removeDuplicateLetters(string s) {
  vector<int> cand(256, 0);
  vector<bool> visited(256, false);

  for (char c : s)
      cand[c]++;

  string result = "0";
  
  for (char c : s) {
      cand[c]--;
      if (visited[c]) continue;
      while (c < result.back() && cand[result.back()]) {
          visited[result.back()] = false;
          result.pop_back();
      }
      result += c;
      visited[c] = true;
  }
  return result.substr(1);
}
