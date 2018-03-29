/* You are given a string representing an attendance record for a student. The record only contains the following three characters:
1. 'A' : Absent.
2. 'L' : Late.
3. 'P' : Present.

A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

You need to return whether the student could be rewarded according to his attendance record.

Example 1:
Input: "PPALLP"
Output: True

Example 2:
Input: "PPALLL"
Output: False */

bool checkRecord(string s) {
  int a = 0, l = 0;
  for(int i = 0;i < s.size(); i++) {
      if(s[i] == 'A') {
        a++;
      }
      if(s[i] == 'L') {
        l++;
      }
      else {
        l = 0;
      }
      if(a >= 2||l > 2) {
        return false;
      }
  }
  return true;
}
