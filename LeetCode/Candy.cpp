// There are N children standing in a line. Each child is assigned a rating value.

// You are giving candies to these children subjected to the following requirements:
// * Each child must have at least one candy.
// * Children with a higher rating get more candies than their neighbors.

// What is the minimum candies you must give?

/* Example 1:
Input: [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.

Example 2:
Input: [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
             The third child gets 1 candy because it satisfies the above two conditions. */

int candy(vector<int>& ratings) {
  if (ratings.empty())
      return 0;

  int total = 0, i = 0, d = 0;
  unsigned off = 0;

  while (off < ratings.size() - 1)
  {
      i = d = 0;
      // Increasing sequence
      while (off < ratings.size() - 1 && ratings[off] < ratings[off + 1])
          ++off, ++i;
      // Decreasing sequence
      while (off < ratings.size() - 1 && ratings[off] > ratings[off + 1])
          ++off, ++d;
      // Add tot total (don't include last element, it will be added by next mountain if present)
      total += (i * (i + 1) + d * (d + 1)) / 2 + std::max(i, d);
      // Handle equal elements
      while (off < ratings.size() - 1 && ratings[off] == ratings[off + 1])
          ++off, ++total;
  }

  // Don't forget to account for the last element of the last mountain, so +1
  return total + 1;
}

// The idea is to split the sequence into "mountains", where a mountain is an increasing sequance followed by a decreasing sequence.

// Take this for example: [3,4,5,6,3,2]. The algorithm will compute length of the increasing sequence [3, 4, 5] -> left = 3 and decreasing sequence [3, 2] -> right = 2 (peak is not included). Then we add (left * (left + 1) + (right * right + 1)) / 2 + max(left, right) + 1 to the total result.

// Consecutive equal elements are treated as mountains formed of a single element.

// One last observation is how I handle the mountain interference. For example: [2,3,2,4,3] has mountains [2,3,2] and [2,4,3] with a common element 2 (the mountain's last element is the next mountain's first element. To handle this I never account for the last element of the mountain, but add 1 to the result in the end.
