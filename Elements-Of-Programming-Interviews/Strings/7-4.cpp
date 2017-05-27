// Write a program that takes as input an array of characters, and removes each 'b' and replaces each 'a' by two 'd's. Specifically, along
// with the array, you are provided an integer-valued size. Size denotes the number of entries of the array that the operation is to be
// applied to. You do not have to worry preserving about subsequent entries.

// Algorithm
// First, we delete 'b's and compute the final number of valid characters of the string, with a forward iteration through the string.
// Then we replace each 'a' by two 'd's, iterating backwards from the end of the resulting string. If there are more 'b's than 'a's, the
// number of valid entries will decrease, and if there are more 'a's than 'b's the number will increase.

int ReplaceAndRemove(int size, char s[]) {
  // Forward iteration: remove 'b's and count the number of 'a's
  int write_idx = 0, a_count = 0;
  for (int i = 0; i < size; i++) {
    if (s[i] != 'b') {
      s[write_idx++] = s[i];
    }
    if (s[i] == 'a') {
      a_count++;
    }
  }

  // Backward iteration: replace 'a's with "dd"s starting from the end
  int cur_idx = write_idx - 1;
  write_idx = write_idx + a_count - 1;
  const int final_size = write_idx + 1;
  while (cur_idx >= 0) {
    if (s[cur_idx] == 'a') {
      s[write_idx--] = 'd';
      s[write_idx--] = 'd';
    } else {
      s[write_idx--] = s[cur_idx];
    }
    cur_idx--;
  }
  return final_size;
}

// The forward and backward iterations each take O(n) time, so the total time complexity is O(n)
