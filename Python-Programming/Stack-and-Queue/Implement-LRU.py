class LRUCache:

    def __init__(self, capacity):
        self.capacity = capacity
        self.cache = set()
        self.cache_values = LinkedList()

    # Set Operation
    def set(self, value):
        node = self.get(value)
        if node == None:
            if (self.cache_values.size >= self.capacity):
                self.cache_values.insert_at_tail(value)
                self.cache.add(value)
                self.cache.remove(self.cache_values.get_head().data)
                self.cache_values.remove_head()
            else:
                self.cache_values.insert_at_tail(value)
                self.cache.add(value)

        else:
            self.cache.remove(value)
            self.cache_values.insert_at_tail(value)

    # Get Operation
    def get(self, value):
        if value not in self.cache:
            return None
        else:
            i = self.cache_values.get_head()
            while i is not None:
                if i.data == value:
                    return i
                i = i.next
