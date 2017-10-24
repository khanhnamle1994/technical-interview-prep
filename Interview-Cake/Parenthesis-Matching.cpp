// "Sometimes (when I nest them (my parentheticals) too much (like this (and this))) they get confusing."
// Write a function that, given a sentence like the one above, along with the position of an opening parenthesis, finds the corresponding
// closing parenthesis.
// Example: if the example string above is input with the number 10 (position of the first parenthesis), the output should be 79
// (position of the last parenthesis).

// Solution
// We simply walk through the the string, starting at our input opening parenthesis position. As we iterate, we keep a count of how many
// additional "(" we find as openNestedParens. When we find a ")" we decrement openNestedParens. If we find a ")" and openNestedParens is
// 0, we know that ")" closes our initial "(", so we return its position.

size_t getClosingParen(const string& sentence, size_t openingParenIndex)
{
  size_t openNestedParens = 0;

  for (size_t position = openingParenIndex + 1; position < sentence.length(); ++position) {
      char c = sentence[position];

      if (c == '(') {
          ++openNestedParens;
      }
      else if (c == ')') {
          if (openNestedParens == 0) {
              return position;
          }
          else {
              --openNestedParens;
          }
      }
  }

  throw invalid_argument("No closing parenthesis :(");
}

// Complexity
// O(n) time, where n is the number of chars in the string. O(1) space.
