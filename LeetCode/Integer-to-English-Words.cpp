// Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 2^31 - 1.

/* For example,
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven" */

string digits[20] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

string tens[10] = {"Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

string int2string(int n) {
    if (n >= 1000000000) {
        return int2string(n / 1000000000) + " Billion" + int2string(n % 1000000000);
    } else if (n >= 1000000) {
        return int2string(n / 1000000) + " Million" + int2string(n % 1000000);
    } else if (n >= 1000) {
        return int2string(n / 1000) + " Thousand" + int2string(n % 1000);
    } else if (n >= 100) {
        return int2string(n / 100) + " Hundred" + int2string(n % 100);
    } else if (n >= 20) {
        return  " " + tens[n / 10] + int2string(n % 10);
    } else if (n >= 1) {
        return " " + digits[n];
    } else {
        return "";
    }
}

string numberToWords(int num) {
  if (num == 0) {
      return "Zero";
  } else {
      string ret = int2string(num);
      return ret.substr(1, ret.length() - 1);
  }
}
