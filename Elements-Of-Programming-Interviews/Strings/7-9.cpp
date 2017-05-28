// Write a program which takes as input a valid Roman number string s and returns the integer it corresponds to

// The brute-force approach is to scan s from left to right, adding the value for the corresponding symbol unless the symbol subsequent to
// the one being considered has a higher value, in which case the pair is one of the six exception cases and the value of the pair is added.

// A slightly easier-to-code solution is to start from the right, and if the symbol after the current one is greater than it, we subtract
// the current symbol.

int RomanToInteger(const string& s) {
  unordered_map<char, int> T = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
  int sum = T[s.back()];
  for (int i = s.length() - 2; i >= 0; i--) {
    if (T[s[i]] < T[s[I+1]]) {
      sum -= T[s[i]];
    } else {
      sum += T[s[i]];
    }
  }
  return sum;
}

// Each character of s is processed in O(1) time, yielding an O(n) overall time complexity, where n is the length of s.
