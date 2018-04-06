// Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.
// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

/* Example:
LRUCache cache = new LRUCache( 2 // capacity );
cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4 */

// The good thing about lists is that iterators are never invalidated by modifiers (unless erasing the element itself). This way, we can store the iterator to the corresponding LRU queue in the values of the hash map. Since using erase on a list with an iterator takes constant time, all operations of the LRU cache run in constant time.

typedef list<int> LI;
typedef pair<int, LI::iterator> PII;
typedef unordered_map<int, PII> HIPII;

void touch(HIPII::iterator it) {
    int key = it->first;
    used.erase(it->second.second);
    used.push_front(key);
    it->second.second = used.begin();
}

HIPII cache;
LI used;
int _capacity;

LRUCache(int capacity) : _capacity(capacity) {}

int get(int key) {
    auto it = cache.find(key);
    if (it == cache.end()) return -1;
    touch(it);
    return it->second.first;
}

void put(int key, int value) {
    auto it = cache.find(key);
    if (it != cache.end()) touch(it);
    else {
    	if (cache.size() == _capacity) {
    		cache.erase(used.back());
    		used.pop_back();
    	}
        used.push_front(key);
      }
    cache[key] = { value, used.begin() };
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
