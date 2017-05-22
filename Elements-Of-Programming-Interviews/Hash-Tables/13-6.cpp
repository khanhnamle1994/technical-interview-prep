// Write a program which takes as input an array and finds the distance between a closes pair of equal entries. For example, if s = <"All",
// "work", "and", "no", "play", "makes", "for", "no", "work", "no", "fun", "and", "no", "results">, then the 2nd and 3rd occurrences of "no"
// is the closest pair.

// The brute-force approach is to iterate overa all pairs of entries, check if they are the same, and if so, if the distance between them
// is less than the smallest such distance seen so far. The time complexity is O(n^2), where n is the array length.

// We can improve upon the brute-force algorithm by noting that when examining an entry, we do not need to look at every other entry - we
// only care about entries which are the same. We can store the set of indices corresponding to a given value using a hash table and iterate
// over all such sets. However, there is a better approach - when processing an entry, all we care about is the closest previous equal entry.
// Specifically, as we scan through the array, we record for each value seen so far, we store in a hash table the latest index at which it
// appears. When processing the element, we use the hash table to see the latest index less than the current index holding the same value.

int FindNearestRepetition(const vector<string>& paragraph) {
  unordered_map<string, int> word_to_latest_index;
  int nearest_repeated_distance = numeric_limits<int>::max();
  for(int i = 0; i < paragraph.size(); i++) {
    auto latest_equal_word = word_to_latest_index.find(paragraph[i]);
    if(latest_equal_word != word_to_latest_index.end()) {
      nearest_repeated_distance = min(nearest_repeated_distance, i - latest_equal_word->second);
    }
    word_to_latest_index[paragraph[i]] = i;
  }
  return nearest_repeated_distance;
}

// The time complexity is O(n), since we perform a constant amount of work per entry
// The space complexity is O(d), where d is the number of distinct entries in the array
