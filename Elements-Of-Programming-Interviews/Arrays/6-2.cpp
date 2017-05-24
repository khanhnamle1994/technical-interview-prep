// Write a program which takes as input an array of digits encoding a decimal number D and updates the array to represent the number D + 1.
// For example, if the input is <1, 2, 9> then you should update the array to <1, 3, 0>.

// We mimic the grade-school algorithm for adding numbers, which entails adding digits starting from the least significant digit, and
// propagate carries. If the result has an additional digit, all digits have to be moved to the right by one.

vector<int> PlusOne(vector<int> A) {
  A.back()++;
  for (int i = A.size() - 1; i > 0 && A[i] == 10; i--) {
    A[i] = 0, A[i - 1]++;
  }
  if (A[0] == 10) {
    // We need additional digit as the most significant digit has a carry-out
    A[0] = 0;
    A.insert(A.begin(), 1);
  }
  return A;
}

// The time complexity is O(n), where n is the length of A.
