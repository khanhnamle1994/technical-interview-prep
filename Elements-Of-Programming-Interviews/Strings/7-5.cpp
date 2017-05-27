// Implement a function which takes as input a string s and returns true if s is a palindromic string

/* Solution: The naive approach is to create a reversed version of s, and compare it with s, skipping non-alphanumeric characters.
This requires additional space proportional to the length of s.

We do not need to create the reverse - rather, we can get the effect of the reverse of s by traversing s from right to left. Specifically,
we use 2 indices to traverse the string, one forwards, the other backwards, skipping non-alphanumeric characters, performing case-insensitive
comparison on the alphanumeric characters. We return false as soon as there is a mismatch. If the indices cross, we have verified palindromicity.
*/

bool isPalindrome(const string& s) {
  // i moves forward, and j moves backward
  int i = 0, j = s.size() - 1;
  while (i < j) {
    // i and j both skip non-alphanumeric characters
    while (!isalnum(s[i]) && i < j) {
      i++;
    }
    while (!isalnum(s[j]) && i < j) {
      j--;
    }
    if (tolower(s[i++]) != tolower(s[j--])) {
      return false;
    }
  }
  return true;
}

// O(n) time complexity (O(1) per character)
