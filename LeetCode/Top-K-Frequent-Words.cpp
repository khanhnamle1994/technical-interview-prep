/* Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words. Note that "i" comes before "love" due to a lower alphabetical order.

Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively. */

vector<string> topKFrequent(vector<string>& words, int k) {
  unordered_map<string, int> freq;
  for(auto w : words){
      freq[w]++;
  }

  auto comp = [&](const pair<string,int>& a, const pair<string,int>& b) {
      return a.second > b.second || (a.second == b.second && a.first < b.first);
  };
  typedef priority_queue< pair<string,int>, vector<pair<string,int>>, decltype(comp) > my_priority_queue_t;
  my_priority_queue_t  pq(comp);

  for(auto w : freq ){
      pq.emplace(w.first, w.second);
      if(pq.size()>k) pq.pop();
  }

  vector<string> output;
  while(!pq.empty()){
      output.insert(output.begin(), pq.top().first);
      pq.pop();
  }
  return output;
}
