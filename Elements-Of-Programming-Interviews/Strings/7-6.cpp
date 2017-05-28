// Implement a function for reversing the words in a string s

// For the general case, reversing s gets the words to their correct relative positions. However, for words that are longer than one
// character, their letters appear in reverse order. This situation can be corrected by reversing the individual words.

void ReverseWords(string* s) {
  // Reverse the whole string first
  reverse(s->begin(), s->end());

  size_t start = 0, end;
  while ((end = s->find(" ", start)) != string::npos) {
    // Reverses each word in the string
    reverse(s->begin() + start, s->begin() + end);
    start = end + 1;
  }

  // Reverses the last word
  reverse(s->begin() + start, s->end());
}

// Since we spend O(1) per character, the time complexity is O(n), where n is the length of s.
