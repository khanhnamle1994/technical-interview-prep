// The ISBN is a unique commercial book identifier. It is a string of length 10. The first 9 characters are digits; the last character is a
// character. The check character is the sum of the first 9 digits, modulo 11, with 10 represented by 'X'. Create a cache for looking up
// prices of books identified by their ISBN. You implement lookup, insert, and remove methods. Use the LRU policy for cache eviction. If an
// ISBN is already present, insert should not change the price, but it should update that entry to be the most recently used entry. Lookup
// should also update that entry to be the most recently used entry.

// Hash tables are ideally suited for fast lookup. We can use a hash table to quickly lookup price by using ISBN as keys. Along with each key,
// we store a value, which is the price and the most recent time a lookup was done on that key. This yields O(1) lookup times on cache hits.

// Inserts into the cache are also O(1) time, until the cache is full. Once the cache fills up, to add a new entry we ahve to find the LRU
// entry, which will be evicted to make place for the new entry. Finding this entry takes O(n) time, where n is the cache size.

// Maintain a separate queue of keys. In the hash table we store for each key a reference to its location in the queue. Each time an ISBN is
// looked up and is found in the hash table, it is moved to the front of the queue. When the length of the queue exceeds n, when a new element
// is added to the cache, the item at the tail of the queue is deleted from the cache, i.e., from the queue and the hash table.

template <size_t capacity>
class LRUCache {
public:
  bool Lookup(int isbn, int* price) {
    auto it  = isbn_price_table_.find(isbn);
    if(it == isbn_price_table_.end()) {
      return false;
    }

    *price = it->second.second;

    // Since the key has just been accessed, move it to the front
    MoveToFront(isbn, it);
    return true;
  }

  void Insert(int isbn, int price) {
    auto it = isbn_price_table_.find(isbn);
    // We add the value for key only if key is not present - we don't update existing values
    if(it != isbn_price_table_.end()) {
      // Specification says we should make isbn the most recently used
      MoveToFront(isbn, it);
    } else {
      if(isbn_price_table_.size() == capacity) {
        // Removes the least recently used ISBN to get space
        isbn_price_table_.erase(lru_queue_.back());
        lru_queue_.pop_back();
      }
      lru_queue_.emplace_front(isbn);
      isbn_price_table_[isbn] = {lru_queue_.begin(), price};
    }
  }

  bool Erase(int isbn) {
    auto it = isbn_price_table_.find(isbn);
    if(it == isbn_price_table_.end()) {
      return false;
    }

    lru_queue_.erase(it->second.first);
    isbn_price_table_.erase(it);
    return true;
  }

private:
  typedef unordered_map<int, pair<list<int>::iterator, int>> Table;

  // Forces this key-value pair to move to the front
  void MoveToFront(int isbn, const Table::iterator& it) {
    lru_queue_.erase(it->second.first);
    lru_queue_.emplace_front(isbn);
    it->second.first = lru_queue_.begin();
  }

  Table isbn_price_table_;
  list<int> lru_queue_;
};

// The time complexity for each lookup is O(1) for the hash table lookup and O(1) for updating the queue
