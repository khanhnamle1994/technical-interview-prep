// Winter is coming! Your first job during the contest is to design a standard heater with fixed warm radius to warm all the houses.

// Now, you are given positions of houses and heaters on a horizontal line, find out minimum radius of heaters so that all houses
// could be covered by those heaters.

// So, your input will be the positions of houses and heaters seperately, and your expected output will be the minimum radius standard
// of heaters.

/* Example 1:
Input: [1,2,3],[2]
Output: 1
Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.

Example 2:
Input: [1,2,3,4],[1,4]
Output: 1
Explanation: The two heater was placed in the position 1 and 4. We need to use radius 1 standard, then all the houses can be warmed. */

/*
Example:    h = house,  * = heater  M = INT_MAX

        h   h   h   h   h   h   h   h   h    houses
        1   2   3   4   5   6   7   8   9    index
        *           *       *                heaters

        0   2   1   0   1   0   -   -   -    (distance to nearest RHS heater)
        0   1   2   0   1   0   1   2   3    (distance to nearest LHS heater)

        0   1   1   0   1   0   1   2   3    (res = minimum of above two)

Result is maximum value in res, which is 3.
*/

int findRadius(vector<int>& houses, vector<int>& heaters) {
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());
    vector<int> res(houses.size(), INT_MAX);

    // For each house, calculate distance to nearest RHS heater
    for (int i = 0, h = 0; i < houses.size() && h < heaters.size();) {
        if (houses[i] <= heaters[h]) {
          res[i] = heaters[h] - houses[i];
          i++;
        } else {
          h++;
        }
    }

    // For each house, calculate distance to nearest LHS heater
    for (int i = houses.size() - 1, h = heaters.size() - 1; i >= 0 && h >= 0;) {
        if (houses[i] >= heaters[h]) {
          res[i] = min(res[i], houses[i] - heaters[h]);
          i--;
        } else {
          h--;
        }
    }
    return *max_element(res.begin(), res.end());
}

// Sorting is O(n log n). The rest is O(n).
