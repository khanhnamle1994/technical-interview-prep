// There is a box protected by a password. The password is n digits, where each letter can be one of the first k digits 0, 1, ..., k-1.

// You can keep inputting the password, the password will automatically be matched against the last n digits entered.

// For example, assuming the password is "345", I can open it when I type "012345", but I enter a total of 6 digits.

// Please return any string of minimum length that is guaranteed to open the box after the entire string is inputted.

/* Example 1:
Input: n = 1, k = 2
Output: "01"
Note: "10" will be accepted too.

Example 2:
Input: n = 2, k = 2
Output: "00110"
Note: "01100", "10011", "11001" will be accepted too. */

int n, k, v;
vector<vector<bool> > visited;
string sequence;

void dfs(int u) {
  for (int i = 0; i < k; ++i) {
      if (!visited[u][i]) {
          visited[u][i] = true;
          dfs((u * k + i) % v);
          sequence.push_back('0' + i);
      }
  }
}

string crackSafe(int n, int k) {
  if (k == 1) return string(n, '0');
  this->n = n;
  this->k = k;
  v = 1;
  for (int i = 0; i < n -1; ++i) v *= k;
  visited.resize(v, vector<bool>(k, false));
  dfs(0);
  return sequence + sequence.substr(0, n - 1);
}
