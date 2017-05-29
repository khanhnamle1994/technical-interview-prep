// Write a function that takes a string as input and reverse only the vowels of a string.
// Example 1: Given s = "hello", return "holle".
// Example 2: Given s = "leetcode", return "leotcede".

// This question let us flip the vowel letters in the string, vowels have five a, e, i, o, u, need to pay attention to the capital is
// also considered, so a total of ten letters. We write a function of isVowel to determine whether the current character is vowel letters,
// if both sides are vowels, then we exchange, if the left is not, move the right one, if the right is not, then move one

class Solution {
public:
  string reverseVowels(string s){
    int left = 0;
    int right = s.size() - 1;
    while (left < right) {
      if (isVowel(s[left]) && isVowel(s[right])) {
        swap(s[left++], s[right--]);
      } else if (isVowel(s[left])) {
        right--;
      } else {
        left++;
      }
    }
    return s;
  }

  bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
  }
}
