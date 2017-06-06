// Given a non-empty array of integers, return the k most frequent elements.
// For example, given [1,1,1,2,2,3] and k = 2, return [1,2].

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        priority_queue<pair<int,int>> heap;
        vector<int> result;
        for (auto a : nums) {
          map[a]++;
        }
        for (auto it : map) {
          heap.push({it.second, it.first});
        }
        for (int i = 0; i < k; i++) {
          result.push_back(heap.top().second);
          heap.pop();
        }
        return result;
    }
};
