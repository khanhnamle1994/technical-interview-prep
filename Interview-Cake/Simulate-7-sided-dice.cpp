// You have a function rand5() that generates a random integer from 1 to 5. Use it to write a function rand7() that generates
// a random integer from 1 to 7.
// rand5() returns each integer with equal probability. rand7() must also return each integer with equal probability.

/* Solution

Because rand5() has only 5 possible outcomes, and we need 7 possible results for rand7(), we need to call rand5() at least twice.

When we call rand5() twice, we have 5*5=25 possible outcomes. If each of our 7 possible results has an equal chance of occuring,
we'll need each outcome to occur in our set of possible outcomes the same number of times. So our total number of possible outcomes
must be divisible by 7.

25 isn't evenly divisible by 7, but 21 is. So when we get one of the last 4 possible outcomes, we throw it out and roll again.

So we roll twice and translate the result into a unique outcomeNumber in the range 1..25. If the outcomeNumber is greater than 21,
we throw it out and re-roll. If not, we mod by 7 (and add 1). */

int rand7()
{
  while (true) {
      // do our die rolls
      int roll1 = rand5();
      int roll2 = rand5();

      int outcomeNumber = (roll1 - 1) * 5 + (roll2 - 1) + 1;

      // if we hit an extraneous
      // outcome we just re-roll
      if (outcomeNumber > 21) {
          continue;
      }

      // our outcome was fine. return it!
      return outcomeNumber % 7 + 1;
  }
}

// Complexity
// Worst-case O(∞) time (we might keep re-rolling forever) and O(1) space.
