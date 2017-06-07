// Write a program which takes as input 2 sorted arrays, and returns a new array containing elements that are present in both of the input
// arrays. The input arrays may have duplicate entries, but the returned array should be free of duplicates. For example, the input is
// <2, 3, 3, 5, 5, 6, 7, 7, 8, 12> and <5, 5, 6, 8, 8, 9, 10, 10>, your output should be <5, 6, 8>

/* Solution:
The brute-force algorithm is a "loop pin" - traversing through all the elements of one array and comparing them to the elements of the other
array. Let m and n be the lengths of the 2 input arrays. The brute-force algorithm has O(mn) time complexity.

Since both the arrays are sorted, we can make some optimizations. First, we can iterate through the first array and use binary search in
an array to test if the element is present in the second array. The time complexity is O(m log n), where m is the length of the array
being iterated over. We can further improve our run time by choosing the shorter array for the outer loop since if n is much smaller than
m, then n log(m) is much smaller than m log(n).

This is the best solution if one set is much smaller than the other. However, it is not the best when the array lengths are similar because
we are not exploiting the fact that both arrays are sorted. We can achieve linear runtime by simultaneously advancing through the 2 input
arrays in increasing order. At each iteration, if the array elements differ, the smaller one can be eliminated. If they are equal, we add
that value to the intersection and advance both. */

vector<int> IntersectTwoSortedArrays(const vector<int>& A, const vector<int>& B) {
  vector<int> intersection_A_B;
  int i = 0, j = 0;
  while(i < A.size() && j < B.size()) {
    if(A[i] == B[j] && (i == 0 || A[i] != A[i-1])) {
      intersection_A_B.emplace_back(A[i]);
      i++;
      j++;
    } else if (A[i] < B[j]) {
      i++;
    } else { // A[i] > B[j]
      j++;
    }
  }
  return intersection_A_B;
}

// Since we spend O(1) time per input array element, the time complexity for the entire algorithm is O(m + n)
