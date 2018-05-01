/* Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true */

int state;

bool check() {
    if (state == 2 || state == 4 || state == 7) return true;
    return false;
}

bool isNumber(string s) {
  if (!s.length()) return false;
  if (s[0] == ' ') return isNumber(s.substr(1, s.length() - 1));
  if (s[s.length() - 1] == ' ') return isNumber(s.substr(0, s.length() - 1));

  state = 0;
  int pos = 0;
  while (pos < s.length()) {
      char c = s[pos];
      switch (state) {
          case 0:
              if (c == '+' || c == '-') {

              } else {
                  pos--;
              }
              state++;
              break;
          case 1:
              if (c == '.') {
                  state = 3;
              } else if (c >= '0' && c <= '9') {
                  state = 2;
              } else {
                  return false;
              }
              break;
          case 2:
              if (c >= '0' && c <= '9') {

              } else if (c == '.') {
                  state = 4;
              } else if (c == 'e') {
                  state = 5;
              } else {
                  return false;
              }
              break;
          case 3:
              if (c >= '0' && c <= '9') {
                  state = 4;
              } else {
                  return false;
              }
              break;
          case 4:
              if (c >= '0' && c <= '9') {

              } else if (c == 'e') {
                  state = 5;
              } else {
                  return false;
              }
              break;
          case 5:
              if (c == '+' || c == '-') {

              } else {
                  pos--;
              }
              state = 6;
              break;
          case 6:
              if (c >= '0' && c <= '9') {
                  state = 7;
              } else {
                  return false;
              }
              break;
          case 7:
              if (c >= '0' && c <= '9') {

              } else {
                  return false;
              }
              break;

      }
      pos++;
  }
  return check();
}
