// Consider a coordinate system for the Milky Way, in which Earth is at (0, 0, 0). Model stars as points, and assume distances are in light
// years. The Milky Way consists of approximately 10^12 stars, and their coordinates are stored in a file. How would you compute the k
// stars which are closest to Earth?

/* Solution:
Intuitively, we only care about stars close to Earth. Therefore, we can keep a set of candidates, and iteratively update the candidate set.
The candidates are the k closest stars we have seen so far. When we examine a new star, we want to see if it should be added to the candidates.
This entails comparing the candidate that is furthest from Earth with the new star. To find this candidate efficiently, we should store
the candidates in a container that supports efficiently extracting the maximum and adding a new member.

A max-heap is perfect for this application. Conceptually, we start by adding the first k stars to the max-heap. As we process the stars,
each time we encounter a new star that is closer to Earth than the star which is furthest from Earth among the stars in the max-heap, we
delete from the max-heap, and add the new one. Otherwise, we discard the new star and continue. We can simplify the code by simply adding
each star to the max-heap, and discarding the maximum element from the max-heap once it contains k + 1 elements. */

struct Star {
  bool operator<(const Star& that) const {
    return Distance() < that.Distance();
  }

  double Distance() const { return sqrt(x*x + y*y + z*z); }
  double x, y, z;
};

vector<Star> FindClosestKStars(int k, istringstream* stars) {
  // max-heap to store the closest k stars seen so far
  priority_queue<Star, vector<Star>> max_heap;

  string line;
  while(getline(*stars, line)) {
    stringstream line_stream(line);
    array<double, 3> data; // stores x, y, and z
    for(int i = 0; i < 3; i++) {
      string buf;
      getline(line_stream, buf, ',');
      data[i] = stod(buf);
    }

    // Add each star to the max-heap. If the max-heap size exceeds k, remove the maximum element from the max-heap
    max_heap.emplace(Star{data[0], data[1], data[2]});
    if(max_heap.size() == k + 1) {
      max_heap.pop();
    }
  }

  // Iteratively extract from the max-heap, which yields the stars sorted according from furthest to closest
  vector<Star> closest_stars;
  while(!max_heap.empty()) {
    closest_stars.emplace_back(max_heap.top());
    max_heap.pop();
  }
  return {closest_stars.rbegin(), closest_stars.rend()};
}

// The time complexity is O(n log k) and the space complexity is O(k)
