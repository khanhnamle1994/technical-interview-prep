// Write a program to test whether the letters forming a string can be permuted to form a palindrome.

// A brute force approach is to compute all permutations of the string, and test each one for palindromicity. This has a very high complexity.
// Examining the approach in more detail, one thing to note is that if a string begins with say 'a', then we only need consider permutations
// that end with 'a'. This observation can be used to prune the permutation-based algorithm. However, a more powerful conclusion is that all
// characters must occur in pairs for a string to be permutable into a palindrome, with one exception, if the string is of odd length.

// More formally, if the string is of even length, a necessary and sufficient condition for it to be a palindrome is that each character in
// the string appear an even number of times. If the length is odd, all but one character in the string appear an even number of times. Both
// these cases are covered by testing that at most one character appears an odd number of times, which can be checked using a hash table
// mapping characters to frequencies.

bool CanFormPalindrome(const string& s) {
  unordered_map<char, int> char_frequencies;
  // compute the frequency of each char in s
  for (char c : s) {
    char_frequencies[c]++;
  }

  // A string can be permuted as a palindrome if and only if the number of chars whose frequencies is odd is at most 1
  int odd_frequency_count = 0;
  return none_of(begin(char_frequencies), end(char_frequencies),
                [&odd_frequency_count](const auto& p) {
                  return (p.second % 2) && odd_frequency_count++ > 1;
                });
}

// The time complexity is O(n), where n is the length of the string.
// The space complexity is O(c), where c is the number of distinct characters appearing in the string.
