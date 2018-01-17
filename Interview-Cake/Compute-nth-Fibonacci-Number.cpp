// Write a function fib() that a takes an integer n and returns the nth Fibonacci number.

/* Let's say our Fibonacci series is 0-indexed and starts with 0. So:
fib(0);  // => 0
fib(1);  // => 1
fib(2);  // => 1
fib(3);  // => 2
fib(4);  // => 3
... */

// Solution
// We use a bottom-up approach, starting with the 0th Fibonacci number and iteratively computing subsequent numbers until we get to n.

int fib(int n)
{
    // edge cases:
    if (n < 0) {
        throw invalid_argument(
            "Index was negative."
            " No such thing as a negative index in a series.");
    }
    else if (n == 0 || n == 1) {
        return n;
    }

    // we'll be building the fibonacci series from the bottom up
    // so we'll need to track the previous 2 numbers at each step
    int prevPrev = 0;  // 0th fibonacci
    int prev = 1;      // 1st fibonacci
    int current = 0;   // Declare and initialize current

    for (int i = 1; i < n; ++i) {

        // Iteration 1: current = 2nd fibonacci
        // Iteration 2: current = 3rd fibonacci
        // Iteration 3: current = 4th fibonacci
        // To get nth fibonacci ... do n-1 iterations.
        current = prev + prevPrev;
        prevPrev = prev;
        prev = current;
    }

    return current;
}

// Complexity
// O(n) time and O(1) space.
