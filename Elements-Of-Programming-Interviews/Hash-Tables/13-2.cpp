// Write a program which takes text for an anonymous letter and text for a magazine and determines if it is possible to write the
// anonymous letter using the magazine. The anonymous letter can be written using the magazine if for each character in the anonymous
// letter, the number of times it appears in the anonymous letter is no more than the number of times it appears in the magazine

// A brute force approach is to count for each character in the character set the number of times it appears in the letter and in the
// magazine. If any character occurs more often in the letter than the magazine we return false, otherwise we return true. This approach
// is potentially slow because it iterates over all characters, including those that do not occur in the letter or magazine. It also
// makes multiple passes over both the letter and the magazine - as many passes as there are characters in the character set.

// A better approach is to make a single pass over the letter, storing the character counts for the letter in a single hash table - keys
// are characters, and values are the number of times that character appears. Next, we make a pass over the magazine. When processing a
// character c, if c appears in the hash table, we reduce its count by 1; we remove it from the hash when its count goes to 0. If the hash
// becomes empty, we return true. If we reach the end of the letter and the hash is non-empty, we return false - each of the characters
// remaining in the hash occurs more times in the letter than the magazine.

bool IsLetterConstructibleFromMagazine(const string& letter_text, const string& magazine_text) {
  unordered_map<char, int> char_frequency_for_letter;
  // Compute the frequencies for all chars in letter_text
  for (char c : letter_text) {
    char_frequency_for_letter[c]++;
  }

  // Check if the characters in magazine_text can cover characters in char_frequency_for_letter
  for (char c : magazine_text) {
    auto it = char_frequency_for_letter.find(c);
    if (it != char_frequency_for_letter.cend()) {
      it->second--;
      if(it->second == 0) {
        char_frequency_for_letter.erase(it);
        if (char_frequency_for_letter.empty()) {
          // All characters for letter_text are matched
          break;
        }
      }
    }
  }
  // Empty char_frequency_for_letter means every char in letter_text can be covered by a character in magazine_text
  return char_frequency_for_letter.empty();
}

// In the worst case, the letter is not constructible or the last character of the magazine is essentially required. Therefore, the time
// complexity is O(m + n) where m and n are the number of characters in the letter and magazine, respectively. The space complexity is
// the size of the hash table constructed in the pass over the letter, i.e., O(L), where L is the number of distinct characters appearing
// in the letter.
