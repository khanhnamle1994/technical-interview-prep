// Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
// Example:
// Given num = 16, return true. Given num = 5, return false.

bool isPowerOfFour(int num) {
  return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;
}
