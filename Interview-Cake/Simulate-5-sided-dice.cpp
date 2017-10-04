// You have a function rand7() that generates a random integer from 1 to 7. Use it to write a function rand5() that generates a random
// integer from 1 to 5.

// rand7() returns each integer with equal probability. rand5() must also return each integer with equal probability.

int rand5()
{
  int result = 7; // arbitrarily large
  while (result > 5) {
      result = rand7();
  }
  return result;
}

// Complexity
// Worst-case O(∞) time (we might keep re-rolling forever) and O(1) space.

// Note that if we weren't worried about the potential space cost of recursion, we could use an arguably-more-readable recursive approach
// with O(∞) space cost:

int rand5()
{
  int roll = rand7();
  if (roll <= 5) {
      return roll;
  }
  else {
      return rand5();
  }
}
