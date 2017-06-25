// The Fibonacci sequence begins with fibonacci(0) = 0 and fibonacci(1) = 1 as its respective first and second terms. After these first
// two elements, each subsequent element is equal to the sum of the previous two elements.

// Given n, complete the fibonacci function so it returns fibonacci(n).

#include <iostream>

using namespace std;

int fibonacci(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
int main() {
    int n;
    cin >> n;
    cout << fibonacci(n);
    return 0;
}
