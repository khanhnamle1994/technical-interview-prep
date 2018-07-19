// On an infinite number line (x-axis), we drop given squares in the order they are given.

// The i-th square dropped (positions[i] = (left, side_length)) is a square with the left-most point being positions[i][0] and sidelength positions[i][1].

// The square is dropped with the bottom edge parallel to the number line, and from a higher height than all currently landed squares. We wait for each square to stick before dropping the next.

// The squares are infinitely sticky on their bottom edge, and will remain fixed to any positive length surface they touch (either the number line or another square). Squares dropped adjacent to each other will not stick together prematurely.

// Return a list ans of heights. Each height ans[i] represents the current highest height of any square we have dropped, after dropping squares represented by positions[0], positions[1], ..., positions[i].

/* Example 1:
Input: [[1, 2], [2, 3], [6, 1]]
Output: [2, 5, 5]
Explanation:

After the first drop of positions[0] = [1, 2]:
_aa
_aa
-------
The maximum height of any square is 2.

After the second drop of positions[1] = [2, 3]:
__aaa
__aaa
__aaa
_aa__
_aa__
--------------
The maximum height of any square is 5.
The larger square stays on top of the smaller square despite where its center
of gravity is, because squares are infinitely sticky on their bottom edge.

After the third drop of positions[1] = [6, 1]:
__aaa
__aaa
__aaa
_aa
_aa___a
--------------
The maximum height of any square is still 5.

Thus, we return an answer of [2, 5, 5].

Example 2:
Input: [[100, 100], [200, 100]]
Output: [100, 100]
Explanation: Adjacent squares don't get stuck prematurely - only their bottom edge can stick to surfaces. */

vector<int> fallingSquares(vector<pair<int, int>>& positions) {
  map<pair<int,int>, int> mp;
  mp[{0,1000000000}] = 0;
  vector<int> ans;
  int mx = 0;

  for (auto &v:positions) {
      vector<vector<int>> toAdd;
      cout << endl;
      int len = v.second, a = v.first, b =v.first + v.second, h = 0;
      auto it = mp.upper_bound({a,a});

      if (it != mp.begin() && (--it)->first.second <= a) ++it;

      while (it != mp.end() && it->first.first <b) {
          if (a > it->first.first) toAdd.push_back({it->first.first,a,it->second});
          if (b < it->first.second) toAdd.push_back({b,it->first.second,it->second});

          h = max(h, it->second);
          it = mp.erase(it);
      }

      mp[{a,b}] = h + len;
      for (auto &t:toAdd) mp[{t[0],t[1]}] = t[2];
      mx = max(mx, h + len);
      ans.push_back(mx);
  }

  return ans;
}
