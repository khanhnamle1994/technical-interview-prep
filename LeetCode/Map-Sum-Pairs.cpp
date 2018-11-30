/* Implement a MapSum class with insert, and sum methods.

For the method insert, you'll be given a pair of (string, integer). The string represents the key and the integer represents the value. If the key already existed, then the original key-value pair will be overridden to the new one.

For the method sum, you'll be given a string representing the prefix, and you need to return the sum of all the pairs' value whose key starts with the prefix.

Example 1:
Input: insert("apple", 3), Output: Null
Input: sum("ap"), Output: 3
Input: insert("app", 2), Output: Null
Input: sum("ap"), Output: 5 */

map<string, int> mp;

/** Initialize your data structure here. */
MapSum() {

}

void insert(string key, int val) {
  mp[key] = val;
}

int sum(string prefix) {
  int sum = 0, n = prefix.size();
  for (auto it = mp.lower_bound(prefix); it != mp.end() && it->first.substr(0, n) == prefix; it++)
      sum += it->second;
  return sum;
}

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
