// A frog is crossing a river. The river is divided into x units and at each unit there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.

// Given a list of stones' positions (in units) in sorted ascending order, determine if the frog is able to cross the river by landing on the last stone. Initially, the frog is on the first stone and assume the first jump must be 1 unit.

// If the frog's last jump was k units, then its next jump must be either k - 1, k, or k + 1 units. Note that the frog can only jump in the forward direction.

/* Example 1:

[0,1,3,5,6,8,12,17]

There are a total of 8 stones.
The first stone at the 0th unit, second stone at the 1st unit,
third stone at the 3rd unit, and so on...
The last stone at the 17th unit.

Return true. The frog can jump to the last stone by jumping
1 unit to the 2nd stone, then 2 units to the 3rd stone, then
2 units to the 4th stone, then 3 units to the 6th stone,
4 units to the 7th stone, and 5 units to the 8th stone.

Example 2:

[0,1,2,3,4,8,9,11]

Return false. There is no way to jump to the last stone as
the gap between the 5th and 6th stone is too large. */

map<pair<int,int>, bool> memo;

bool helper(const vector<int>& stones, int idx, int k)
{
    if (k < 1)
      return false;

    pair<int,int> x = make_pair(idx,k);

    if (memo.find(x) != memo.end())
    {
      return memo[x];
    }

    if (idx == stones.size() - 1)
      return true;

    int pos = stones[idx] + k;

    for (int i = idx + 1; i < stones.size(); ++i)
    {
      if (stones[i] > pos)
        return false;

      if (stones[i] == pos)
      {
        memo[x] = helper(stones, i, k-1) || helper(stones, i, k) || helper(stones, i, k+1);
        return memo[x];
      }
    }

    return false;
}

bool canCross(vector<int>& stones) {
  return helper(stones, 0, 1);
}

/* I define a recusive function that takes as input the last position and jump that the frog made. The new position is then equal to last_position + last_jump.

>> If this position corresponds to the last stone, return true.
>> If this position doesn't correspond to any stone location, return false.
>> Otherwise, recursively call this function from the new position with jumps of k -1, k, and k + 1 and return the OR of those results.

Use memoization to save intermediate results.
