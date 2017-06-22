// Alice is taking a cryptography class and finding anagrams to be very useful. We consider two strings to be anagrams of each other if
// the first string's letters can be rearranged to form the second string. In other words, both strings must contain the same exact
// letters in the same exact frequency For example, bacdc and dcbac are anagrams, but bacdc and dcbad are not.

// Alice decides on an encryption scheme involving two large strings where encryption is dependent on the minimum number of character
// deletions required to make the two strings anagrams. Can you help her find this number?

// Given two strings, a and b, that may or may not be of the same length, determine the minimum number of character deletions required
// to make a and b anagrams. Any characters can be deleted from either of the strings.

int number_needed(string a, string b) {
    unordered_map<char, int> m1, m2;
    int count = 0;

    for(int i = 0; i < a.length(); i++) {
        if(m1.count(a[i]) == 0) {
            m1[a[i]] = 1;
        } else {
            m1[a[i]]++;
        }
    }

    for(int j = 0; j < b.length(); j++) {
        if(m2.count(b[j]) == 0) {
            m2[b[j]] = 1;
        } else {
            m2[b[j]]++;
        }
    }

    for(auto it : m1) {
        if(m2[it.first] == 0) {
            count += m1[it.first];
        } else {
            count += max(0, m1[it.first] - m2[it.first]);
        }
    }

    for(auto it : m2) {
        if(m1[it.first] == 0) {
            count += m2[it.first];
        } else {
            count += max(0, m2[it.first] - m1[it.first]);
        }
    }

    return count;
}
