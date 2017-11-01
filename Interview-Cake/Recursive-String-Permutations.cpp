// Write a recursive function for generating all permutations of an input string. Return them as a set.

// If we're making all permutations for "cat," we take all permutations for "ca" and then put "t" in each possible position in
// each of those permutations. We use this approach recursively:

set<string> getPermutations(const string& inputString)
{
  set<string> permutations;

  // base case
  if (inputString.length() <= 1) {
      permutations.insert(inputString);
      return permutations;
  }

  string allCharsExceptLast = inputString.substr(0, inputString.length() - 1);
  char lastChar = inputString[inputString.length() - 1];

  // recursive call: get all possible permutations for all chars except last
  set<string> permutationsOfAllCharsExceptLast = getPermutations(allCharsExceptLast);

  // put the last char in all possible positions for each of the above permutations
  for (const string& permutationOfAllCharsExceptLast : permutationsOfAllCharsExceptLast) {
      for (size_t position = 0; position <= allCharsExceptLast.length(); ++position) {
          string permutation = permutationOfAllCharsExceptLast.substr(0, position)
                  + lastChar + permutationOfAllCharsExceptLast.substr(position);
          permutations.insert(permutation);
      }
  }

  return permutations;
}
