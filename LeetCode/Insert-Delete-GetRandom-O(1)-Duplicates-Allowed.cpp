/* Design a data structure that supports all following operations in average O(1) time.

Note: Duplicate elements are allowed.
1 - insert(val): Inserts an item val to the collection.
2 - remove(val): Removes an item val from the collection if present.
3 - getRandom: Returns a random element from current collection of elements. The probability of each element being returned is linearly related to the number of same value the collection contains.

Example:

// Init an empty collection.
RandomizedCollection collection = new RandomizedCollection();

// Inserts 1 to the collection. Returns true as the collection did not contain 1.
collection.insert(1);

// Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
collection.insert(1);

// Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
collection.insert(2);

// getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
collection.getRandom();

// Removes 1 from the collection, returns true. Collection now contains [1,2].
collection.remove(1);

// getRandom should return 1 and 2 both equally likely.
collection.getRandom(); */

int n;
unordered_map<int,int> f;
vector<int> a;

/** Initialize your data structure here. */
RandomizedCollection() {
  n = 0;
  f.clear();
  a.clear();
}

/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
bool insert(int val) {
  f[val]++;
  n++;
  a.push_back(val);
  return f[val] == 1;
}

/** Removes a value from the collection. Returns true if the collection contained the specified element. */
bool remove(int val) {
  if (f.find(val) != f.end() && f[val] != 0) {
      f[val]--;
      n--;
      return true;
  }
  return false;
}

/** Get a random element from the collection. */
int getRandom() {
  if (n * 1.3 < a.size()) {
      a.resize(n);
      int ai = 0;
      for(auto it: f)
          for(int i = 0; i < it.second; i++)
              a[ai++] = it.first;
  }
  while(1) {
      int x = a[rand() % a.size()];
      if (f[x] != 0)
          return x;
  }
  return -1;
}

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
