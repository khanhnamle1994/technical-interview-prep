// The Hamming distance between 2 integers is the number of positions at which the corresponding bits are different. Given 2 integers x
// and y, calculate the Hamming distance
#include <iostream>
using namespace std;

int hammingDistance(int x, int y) {
  int diffs = 0;
  int val = x ^ y;

  while(val != 0) {
    diffs++;
    val &= (val - 1);
  }

  return diffs;
}

int main() {
  cout << hammingDistance(9, 6) << endl;
  return 0;
}
