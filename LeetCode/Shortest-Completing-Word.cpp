// Find the minimum length word from a given dictionary words, which has all the letters from the string licensePlate. Such a word is said to complete the given string licensePlate

// Here, for letters we ignore case. For example, "P" on the licensePlate still matches "p" on the word.

// It is guaranteed an answer exists. If there are multiple answers, return the one that occurs first in the array.

// The license plate might have the same letter occurring multiple times. For example, given a licensePlate of "PP", the word "pair" does not complete the licensePlate, but the word "supper" does.

/* Example 1:
Input: licensePlate = "1s3 PSt", words = ["step", "steps", "stripe", "stepple"]
Output: "steps"
Explanation: The smallest length word that contains the letters "S", "P", "S", and "T".
Note that the answer is not "step", because the letter "s" must occur in the word twice.
Also note that we ignored case for the purposes of comparing whether a letter exists in the word.

Example 2:
Input: licensePlate = "1s3 456", words = ["looks", "pest", "stew", "show"]
Output: "pest"
Explanation: There are 3 smallest length words that contains the letters "s".
We return the one that occurred first. */

string shortestCompletingWord(string licensePlate, vector<string>& words) {
  int lic[26]={0};
  for(int i=0;i<licensePlate.size();i++) {
      if(licensePlate[i]>='a'&&licensePlate[i]<='z') lic[licensePlate[i]-'a']++;
      else if(licensePlate[i]>='A'&&licensePlate[i]<='Z') lic[licensePlate[i]-'A']++;
  }
  int len=INT_MAX;
  string res;
  for(int i=0;i<words.size();i++) {
      int temp[26]={0};
      for(int j=0;j<words[i].size();j++) temp[words[i][j]-'a']++;
      int j=0;
      for(j;j<26;j++) {
          if(temp[j]<lic[j]) break;
      }
      if(j==26) {
          if(words[i].size()<len) {
              len=words[i].size();
              res=words[i];
          }
      }
  }
  return res;
}
