// Write an efficient function that checks whether any permutation of an input string is a palindrome.
// You can assume the input string only contains lowercase letters.

/* Examples:
"civic" should return true
"ivicc" should return true
"civil" should return false
"livci" should return false */

// Solution

/* Our approach is to check that each character appears an even number of times, allowing for only one characters to appear an odd
number of times (a middle character). This is enough to determine if a permutation of the input string is a palindrome.

We iterate through each character in the input string, keeping track of the characters we’ve seen an odd number of times using a
unordered set unpairedCharacters.

As we iterate through the characters in the input string:
>> If the character is not in unpairedCharacters, we add it.
>> If the character is already in unpairedCharacters, we remove it.

Finally, we just need to check if less than two characters don’t have a pair.
*/

bool hasPalindromePermutation(const string& str)
{
  // track characters we've seen an odd number of times
  unordered_set<char> unpairedCharacters;

  for (char c : str) {
      if (unpairedCharacters.find(c) != unpairedCharacters.end()) {
          unpairedCharacters.erase(c);
      }
      else {
          unpairedCharacters.insert(c);
      }
  }

  // the string has a palindrome permutation if it
  // has one or zero characters without a pair
  return unpairedCharacters.size() <= 1;
}

// Complexity

/* O(n) time, since we're making one iteration through the nn characters in the string.

Our unpairedCharacters unordered set is the only thing taking up non-constant space. We could say our space cost is O(n) as well,
since the set of unique characters is less than or equal to nn. But we can also look at it this way: there are only so many different
characters. How many? The ASCII character set has just 128 different characters (standard english letters and punctuation), while
Unicode has 110,000 (supporting several languages and some icons/symbols). We might want to treat our number of possible characters
in our character unordered set as another variable kk and say our space complexity is O(k). Or we might want to just treat it as a
constant, and say our space complexity is O(1). */
