// Implement an algorithm that takes as input an array of distinct elements and a size, and returns a subset of the given size of the
// array elements. All subsets should be equally likely. Return the result in input array itself.

// The key to efficiently building a random subset of size exactly k is to first build one of size k - 1 and then adding one more element,
// selected randomly from the rest. The problem is trivial when k = 1. We make one call to the random number generator, take the returned
// value mod n, and swap A[0] with A[r]. The entry A[0] now holds the result.

// For k > 1, we begin by choosing one element at random as above and we now repeat the same process with the n - 1 element subarray
// A[1:n - 1]. Eventually, the random subset occupies the slots A[0:k - 1] and the remaining elements are in the last n - k slots.

// Intuitively, if all subsets of size k are equally likely, then the construction process ensures that the subsets of size k + 1 are also
// equally likely. A formal proof, which we do not present, uses mathematical introduction - the induction hypothesis is that every
// permutation of every size k subset of A is equally likely to be in A[0:k - 1].

void RandomSampling(int k, vector<int>* A_ptr) {
  vector<int>& A = *A_ptr;
  default_random_engine seed((random_device())()); // Random num generator
  for (int i = 0; i < k; i++) {
    // Generate a random index in [i, A.size() - 1]
    swap(A[i], A[uniform_int_distribution<int>{i, static_cast<int>(A.size()) - 1}(seed)]);
  }
}

// The algorithm runs in O(1) space. The time complexity is O(k) to select the elements.
