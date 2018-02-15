// Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.

/* Example 1:
Input: "owoztneoer"
Output: "012"

Example 2:
Input: "fviefuro"
Output: "45" */

string originalDigits(string s) {
  vector<string> words = {"zero", "two", "four", "six", "eight", "one", "three", "five", "seven", "nine"};
  vector<int> nums = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
  vector<int> distinct_char = {'z', 'w', 'u', 'x', 'g', 'o', 'r', 'f', 'v', 'i'};
  vector<int> counts(26, 0);

  string result;
  for(auto ch : s){
    counts[ch-'a']++;
  }

  for(int i = 0; i < 10; i++){
      int count = counts[distinct_char[i]-'a'];
      for(int j = 0; j < words[i].size(); j++)
          counts[words[i][j]-'a'] -= count;
      while(count--)
          result += to_string(nums[i]);
  }
  sort(result.begin(), result.end());
  return result;
}
