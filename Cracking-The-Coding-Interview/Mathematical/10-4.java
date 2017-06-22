// Write a method to implement *, - , / operations. You should use only the + operator

/* With an understanding of what each operation (minus, times, divide) does, this problem can be approached logically.
»» Subtraction should be relatively straightforward, as we all know that a - b is the same thing as a + (-1) * b.
»» Multiplication: we have to go back to what we learned in grade school: 21 * 3 = 21 + 21 + 21. It’s slow, but it works.
»» Division is the trickiest, because we usually think of 21 / 3 as something like “if you divide a 21 foot board into 3 pieces, how big
is each piece?” If we think about it the other way around, it’s a little easier: “I divided a 21 foot board in x pieces and got pieces of
3 feet each, how many pieces were there?” From here, we can see that if we continuously subtract 3 feet from 21 feet, we’ll know how many
pieces there are. That is, we continuously subtract b from a and count how many times we can do that. */

// Flip a positive sign to negative, or a negative sign to positive
public static int FnNegate(int a) {
  int neg = 0;
  int d = a < 0 ? 1 : -1;
  while(a != 0) {
    neg += d;
    a += d;
  }
  return neg;
}

// Subtract 2 numbers by negating b and adding them
public static int FnMinus(int a, int b) {
  return a + FnNegate(b);
}

// Check if a and b are different signs
public static boolean DifferentSigns(int a, int b) {
  return ((a < 0 && b > 0) || (a > 0 && b < 0)) ? true : false;
}

// Return absolute value
public static int abs(int a) {
  if(a < 0) return FnNegate(a);
  else return a;
}

// Multiply a by b by adding a to itself b times
public static int FnTimes(int a, int b) {
  if (a < b) return FnTimes(b, a); // algo is faster if b < a
  int sum = 0;
  for (int iter = abs(b); iter > 0; --iter) sum += a;
  if (b < 0) sum = FnNegate(sum);
  return sum;
}

// Divide a by b by literally counting how many times does b go into a. That is, count how many times you can subtract b from a until
// you hit 0.
public static int FnDivide(int a, int b) throws java.lang.ArithmeticException {
  if (b == 0) {
    throw new java.lang.ArithmeticException(“Divide by 0.”);
  }
  int quotient = 0;
  int divisor = FnNegate(abs(b));
  int divend; /* dividend */
  for (divend = abs(a); divend >= abs(divisor); divend += divisor) {
    ++quotient;
  }
  if (DifferentSigns(a, b)) quotient = FnNegate(quotient);
  return quotient;
}

/* Observation and Suggestions
» A logical approach of going back to what exactly multiplication and division do comes in handy. Remember that. All (good) interview
problems can be approached in a logical, methodical way!
»» The interviewer is looking for this sort of logical work-your-way-through-it approach.
»» This is a great problem to demonstrate your ability to write clean code—specifically, to show your ability to re-use code. For
example, if you were writing this solution and didn’t put FnNegate in its own method, you should move it out once you see that you’ll
use it multiple times.
»» Be careful about making assumptions */
