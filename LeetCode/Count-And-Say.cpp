// Give an integer n, generate the nth term of the count-and-say sequence

/* The count-and-say sequence is the sequence of integers with the first 5 terms as following:
1. 1
2. 11
3. 21
4. 1211
5. 111221
*/
#include <iostream>
#include <string>
using namespace std;

string compare(string current) {
  string previous;
  char ch = current[0];
  int count = 1;
  for(int i = 1; i < current.length(); i++) {
    if(current[i] == ch) {
      count++;
    } else {
      char chr = count + '0';
      previous = previous + chr;
      previous = previous + ch;
      ch = current[i];
      count = 1;
    }
  }
  return previous;
}

string countAndSay(int n) {
  if(n == 1) { return "1"; }
  string current;
  string previous = "1";
  for(int i = 2; i <= n; i++) {
    current = compare(previous);
    previous = current;
  }
  return current;
}
