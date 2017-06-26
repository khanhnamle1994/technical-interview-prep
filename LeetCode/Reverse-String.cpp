// Write a function that takes a string as input and returns the string reversed.

// Example: Given s = "hello", return "olleh".

class Solution {
public:
    string reverseString(string s) {
        int i = 0;
        int j = s.length() - 1;
        while(i < j) {
            int temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
        return s;
    }
};
