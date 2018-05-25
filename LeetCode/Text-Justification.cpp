// Given an array of words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

// You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

// Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

// For the last line of text, it should be left justified and no extra space is inserted between words.

/* Example 1:

Input:
words = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth = 16

Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]

Example 2:

Input:
words = ["What","must","be","acknowledgment","shall","be"]
maxWidth = 16

Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be",
             because the last line must be left-justified instead of fully-justified.
             Note that the second line is also left-justified becase it contains only one word.
Example 3:

Input:
words = ["Science","is","what","we","understand","well","enough","to","explain",
         "to","a","computer.","Art","is","everything","else","we","do"]
maxWidth = 20

Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
] */

vector<string> fullJustify(vector<string>& words, int maxWidth) {
  vector<string> res;
  for(int i = 0, k, l; i < words.size(); i += k) {
      for(k = l = 0; i + k < words.size() and l + words[i+k].size() <= maxWidth - k; k++) {
          l += words[i+k].size();
      }
      string tmp = words[i];
      for(int j = 0; j < k - 1; j++) {
          if(i + k >= words.size()) {
            tmp += " ";
          } else {
            tmp += string((maxWidth - l) / (k - 1) + (j < (maxWidth - l) % (k - 1)), ' ');
          }
          tmp += words[i+j+1];
      }
      tmp += string(maxWidth - tmp.size(), ' ');
      res.push_back(tmp);
  }
  return res;
}
