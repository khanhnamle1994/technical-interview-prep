// Given an absolute path for a file (Unix-style), simplify it.

/* For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c" */

string simplifyPath(string path) {
  string res, tmp;
  vector<string> stk;
  stringstream ss(path);
  while(getline(ss,tmp,'/')) {
      if (tmp == "" or tmp == ".") continue;
      if (tmp == ".." and !stk.empty()) stk.pop_back();
      else if (tmp != "..") stk.push_back(tmp);
  }
  for(auto str : stk) res += "/"+str;
  return res.empty() ? "/" : res;
}

// C++ also have getline which acts like Java's split. I guess the code can comment itself.
