/* A password is considered strong if below conditions are all met:
1 - It has at least 6 characters and at most 20 characters.
2 - It must contain at least one lowercase letter, at least one uppercase letter, and at least one digit.
3 - It must NOT contain three repeating characters in a row ("...aaa..." is weak, but "...aa...a..." is strong, assuming other conditions are met).

Write a function strongPasswordChecker(s), that takes a string s as input, and return the MINIMUM change required to make s a strong password. If s is already strong, return 0.

Insertion, deletion or replace of any one character are all considered as one change. */

int strongPasswordChecker(string s) {
  int deleteTarget = max(0, (int)s.length() - 20), addTarget = max(0, 6 - (int)s.length());
  int toDelete = 0, toAdd = 0, toReplace = 0, needUpper = 1, needLower = 1, needDigit = 1;

  ///////////////////////////////////
  // For cases of s.length() <= 20 //
  ///////////////////////////////////
  for (int l = 0, r = 0; r < s.length(); r++) {
      if (isupper(s[r])) { needUpper = 0; }
      if (islower(s[r])) { needLower = 0; }
      if (isdigit(s[r])) { needDigit = 0; }

      if (r - l == 2) {                                   // if it's a three-letter window
          if (s[l] == s[l + 1] && s[l + 1] == s[r]) {     // found a three-repeating substr
              if (toAdd < addTarget) { toAdd++, l = r; }  // insert letter to break repetition if possible
              else { toReplace++, l = r + 1; }            // replace current word to avoid three repeating chars
          } else { l++; }                                 // keep the window with no more than 3 letters
      }
  }
  if (s.length() <= 20) { return max(addTarget + toReplace, needUpper + needLower + needDigit); }

  //////////////////////////////////
  // For cases of s.length() > 20 //
  //////////////////////////////////
  toReplace = 0;                                          // reset toReplace
  vector<unordered_map<int, int>> lenCnts(3);             // to record repetitions with (length % 3) == 0, 1 or 2
  for (int l = 0, r = 0, len; r <= s.length(); r++) {     // record all repetion frequencies
      if (r == s.length() || s[l] != s[r]) {
          if ((len = r - l) > 2) { lenCnts[len % 3][len]++; } // we only care about repetions with length >= 3
          l = r;
      }
  }

  /*
      Use deletions to minimize replacements, following below orders:
      (1) Try to delete one letter from repetitions with (length % 3) == 0. Each deletion decreases replacement by 1
      (2) Try to delete two letters from repetitions with (length % 3) == 1. Each deletion decreases repalcement by 1
      (3) Try to delete multiple of three letters from repetions with (length % 3) == 2. Each deletion (of three
      letters) decreases repalcements by 1
  */
  for (int i = 0, numLetters, dec; i < 3; i++) {
      for (auto it = lenCnts[i].begin(); it != lenCnts[i].end(); it++) {
          if (i < 2) {
              numLetters = i + 1, dec = min(it->second, (deleteTarget - toDelete) / numLetters);
              toDelete += dec * numLetters;               // dec is the number of repetitions we'll delete from
              it->second -= dec;                          // update number of repetitions left

              // after letters deleted, it fits in the group where (length % 3) == 2
              if (it->first - numLetters > 2) { lenCnts[2][it->first - numLetters] += dec; }
          }

          // record number of replacements needed
          // note if len is the length of repetition, we need (len / 3) number of replacements
          toReplace += (it->second) * ((it->first) / 3);
      }
  }

  int dec = (deleteTarget - toDelete) / 3;                // try to delete multiple of three letters as many as possible
  toReplace -= dec, toDelete -= dec * 3;
  return deleteTarget + max(toReplace, needUpper + needLower + needDigit);
}
