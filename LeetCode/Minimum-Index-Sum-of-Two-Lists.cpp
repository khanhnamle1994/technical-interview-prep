// Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list of favorite restaurants represented by strings.

// You need to help them find out their common interest with the least list index sum. If there is a choice tie between answers, output all of them with no order requirement. You could assume there always exists an answer.

/* Example 1:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
Output: ["Shogun"]
Explanation: The only restaurant they both like is "Shogun".

Example 2:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["KFC", "Shogun", "Burger King"]
Output: ["Shogun"]
Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1). */

vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
  vector<string>res;
  unordered_map<string,int>m;
  int min = INT_MAX;

  for(int i = 0; i < list1.size(); i++) {
    m[list1[i]] = i;
  }

  for(int i = 0; i < list2.size(); i++) {
    if(m.count(list2[i]) != 0) {
      if(m[list2[i]] + i < min) {
        min = m[list2[i]] + i, res.clear(), res.push_back(list2[i]);
      }
      else if(m[list2[i]] + i == min) {
        res.push_back(list2[i]);
      }
    }
  }
  return res;
}
