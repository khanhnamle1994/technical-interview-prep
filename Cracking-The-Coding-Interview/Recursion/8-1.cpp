// Write a method to generate the nth Fibonacci number

#include <iostream>
using namespace std;

// Using Recursion
int fibonacci1(int n) {
  if(n == 0) return 0;
  if(n == 1) return 1;
  return fibonacci1(n - 1) + fibonacci1(n - 2);
}

// Time Complexity: T(n) = T(n-1) + T(n-2) + θ(1) which is exponential.

// Bottom-up Dynamic Programming Solution
int fibonacci2(int n) {
  if(n == 0) return 0;
  if(n == 1) return 1;

  int last1 = 0;
  int last2 = 1;
  int ans = 0;

  for(int i = 0; i < n - 1; i++) {
    ans = last1 + last2;
    last1 = last2;
    last2 = ans;
  }
  return ans;
}

// Time Complexity: O(n), Extra Space: O(1)

int main() {
	int n = 10;
	cout << fibonacci1(n) << " " << fibonacci2(n);
	return 0;
}
