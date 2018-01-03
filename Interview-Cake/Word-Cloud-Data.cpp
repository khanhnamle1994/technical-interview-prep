// You want to build a word cloud, an infographic where the size of a word corresponds to how often it appears in the body of text.

// To do this, you'll need data. Write code that takes a long string and builds its word cloud data in an unordered map ↴ , where the keys
// are words and the values are the number of times the words occurred.

// Think about capitalized words. For example, look at these sentences:
// "After beating the eggs, Dana read the next step:"
// "Add milk and eggs, then add flour and sugar."

// What do we want to do with "After", "Dana", and "add"? In this example, your final unordered map should include one "Add" or "add" with
// a value of 22. Make reasonable (not necessarily perfect) decisions about cases like "After" and "Dana".

// Assume the input will only contain words and standard punctuation.

/* Solution
In our solution, we make two decisions:
1 - We use a class. This allows us to tie our methods together, calling them on instances of our class instead of passing references.
2 - To handle duplicate words with different cases, we choose to make a word uppercase in our unordered map only if it is always uppercase
in the original string. While this is a reasonable approach, it is imperfect (consider proper nouns that are also lowercase words, like
"Bill" and "bill").

To split the words in the input string and populate an unordered map of the unique words to the number of times they occurred, we:
1 - Split words by spaces and ellipses—making sure to include hyphens surrounded by characters. We also include all apostrophes (which will
handle contractions nicely but will break possessives into separate words).
2 - Populate the words in our unordered map as they are identified, checking if the word is already in our unordered map in its current case
or another case.

If the input word is uppercase and there's a lowercase version in the unordered map, we increment the lowercase version's count. If the
input word is lowercase and there's an uppercase version in the unordered map, we "demote" the uppercase version by adding the lowercase
version and giving it the uppercase version's count. */

class WordCloudData
{
private:
  unordered_map<string, size_t> wordsToCounts_;

  void populateWordsToCounts(const string& inputString)
  {
      // iterates over each character in the input string, splitting
      // words and passing them to addWordToHashMap()

      size_t currentWordStartIndex = 0;
      size_t currentWordLength = 0;

      for (size_t i = 0; i < inputString.length(); ++i) {
          char character = inputString[i];

          // if we reached the end of the string we check if the last
          // character is a letter and add the last word to our hash map
          if (i == inputString.length() - 1) {
              if (isalpha(character)) {
                  if (currentWordLength == 0) {
                      currentWordStartIndex = i;
                  }
                  ++currentWordLength;
              }
              if (currentWordLength > 0) {
                  string currentWord = inputString.substr(currentWordStartIndex, currentWordLength);
                  addWordToHashMap(currentWord);
              }
          }

          // if we reach a space we know we're at the end of a word
          // so we add it to our hash map and reset our current word
          else if (character == ' ') {
              if (currentWordLength > 0) {
                  string currentWord = inputString.substr(currentWordStartIndex, currentWordLength);
                  addWordToHashMap(currentWord);
                  currentWordLength = 0;
              }
          }

          // we want to make sure we split on ellipses so if we get two periods in
          // a row we add the current word to our hash map and reset our current word
          else if (character == '.') {
              if (i < inputString.length() - 1 && inputString[i + 1] == '.') {
                  if (currentWordLength > 0) {
                      string currentWord = inputString.substr(currentWordStartIndex, currentWordLength);
                      addWordToHashMap(currentWord);
                      currentWordLength = 0;
                  }
              }
          }

          // if the character is a letter or an apostrophe, we add it to our current word
          else if (isalpha(character) || character == '\'') {
              if (currentWordLength == 0) {
                  currentWordStartIndex = i;
              }
              ++currentWordLength;
          }

          // if the character is a hyphen, we want to check if it's surrounded by letters
          // if it is, we add it to our current word
          else if (character == '-') {
              if (i > 0 && isalpha(inputString[i - 1])
                      && isalpha(inputString[i + 1])) {
                  if (currentWordLength == 0) {
                      currentWordStartIndex = i;
                  }
                  ++currentWordLength;
              }
              else if (currentWordLength > 0) {
                  string currentWord = inputString.substr(currentWordStartIndex, currentWordLength);
                  addWordToHashMap(currentWord);
                  currentWordLength = 0;
              }
          }
      }
  }

  void addWordToHashMap(const string& word)
  {
      // if the word is already in the hash map we increment its count
      auto it = wordsToCounts_.find(word);
      if (it != wordsToCounts_.end()) {
          ++it->second;
      }

      // if a lowercase version is in the hash map,
      // we know our input word must be uppercase
      // but we only include uppercase words if they're always uppercase
      // so we just increment the lowercase version's count
      else if ((it = wordsToCounts_.find(toLowerCase(word))) != wordsToCounts_.end()) {
          ++it->second;
      }

      // if an uppercase version is in the hash map,
      // we know our input word must be lowercase.
      // since we only include uppercase words if they're always uppercase,
      // we add the lowercase version and give it the uppercase version's count
      else if ((it = wordsToCounts_.find(capitalize(word))) != wordsToCounts_.end()) {
          size_t newCount = it->second + 1;
          wordsToCounts_.erase(it);
          wordsToCounts_.insert(make_pair(word, newCount));
      }

      // otherwise, the word is not in the hash map at all, lowercase or uppercase
      // so we add it to the hash map
      else {
          wordsToCounts_.insert(make_pair(word, 1));
      }
  }

  static string toLowerCase(const string& word)
  {
      string result = word;
      transform(result.begin(), result.end(), result.begin(), ::tolower);
      return result;
  }

  static string capitalize(const string& word)
  {
      string result = word;
      result[0] = toupper(result[0]);
      return result;
  }

public:
  WordCloudData (const string& inputString)
  {
      populateWordsToCounts(inputString);
  }

  const unordered_map<string, size_t> getWordsToCounts() const
  {
      return wordsToCounts_;
  }
};

/* Complexity
Runtime and memory cost are both O(n)O(n). This is the best we can do because we have to look at every character in the input string and
we have to return an unordered map of every unique word. We optimized to only make one pass over our input and have only one O(n) data
structure. */
