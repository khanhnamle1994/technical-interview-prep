/* Implement a data structure supporting the following operations:
1 - Inc(Key) - Inserts a new key with value 1. Or increments an existing key by 1. Key is guaranteed to be a non-empty string.
2 - Dec(Key) - If Key's value is 1, remove it from the data structure. Otherwise decrements an existing key by 1. If the key does not exist, this function does nothing. Key is guaranteed to be a non-empty string.
3 - GetMaxKey() - Returns one of the keys with maximal value. If no element exists, return an empty string "".
4 - GetMinKey() - Returns one of the keys with minimal value. If no element exists, return an empty string "". */

struct Bucket { int value; unordered_set<string> keys; };
list<Bucket> buckets;
unordered_map<string, list<Bucket>::iterator> bucketOfKey;

/** Initialize your data structure here. */
AllOne() {

}

/** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
void inc(string key) {
  // If the key doesn't exist, insert it with value 0.
  if (!bucketOfKey.count(key))
      bucketOfKey[key] = buckets.insert(buckets.begin(), {0, {key}});

  // Insert the key in next bucket and update the lookup.
  auto next = bucketOfKey[key], bucket = next++;
  if (next == buckets.end() || next->value > bucket->value + 1)
      next = buckets.insert(next, {bucket->value + 1, {}});
  next->keys.insert(key);
  bucketOfKey[key] = next;

  // Remove the key from its old bucket.
  bucket->keys.erase(key);
  if (bucket->keys.empty())
      buckets.erase(bucket);
}

/** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
void dec(string key) {
  // If the key doesn't exist, just leave.
  if (!bucketOfKey.count(key))
      return;

  // Maybe insert the key in previous bucket and update the lookup.
  auto prev = bucketOfKey[key], bucket = prev--;
  bucketOfKey.erase(key);
  if (bucket->value > 1) {
      if (bucket == buckets.begin() || prev->value < bucket->value - 1)
          prev = buckets.insert(bucket, {bucket->value - 1, {}});
      prev->keys.insert(key);
      bucketOfKey[key] = prev;
  }

  // Remove the key from its old bucket.
  bucket->keys.erase(key);
  if (bucket->keys.empty())
      buckets.erase(bucket);
}

/** Returns one of the keys with maximal value. */
string getMaxKey() {
  return buckets.empty() ? "" : *(buckets.rbegin()->keys.begin());
}

/** Returns one of the keys with Minimal value. */
string getMinKey() {
  return buckets.empty() ? "" : *(buckets.begin()->keys.begin());
}

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */
