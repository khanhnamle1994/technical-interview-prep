// A kidnapper wrote a ransom note but is worried it will be traced back to him. He found a magazine and wants to know if he can cut out
// whole words from it and use them to create an untraceable replica of his ransom note. The words in his note are case-sensitive and he
// must use whole words available in the magazine, meaning he cannot use substrings or concatenation to create the words he needs.

// Given the words in the magazine and the words in the ransom note, print Yes if he can replicate his ransom note exactly using whole
// words from the magazine; otherwise, print No.

bool ransom_note(vector<string> magazine, vector<string> ransom) {
    unordered_map<string, int> map;
    for(int i = 0; i < magazine.size(); i++) {
        if(map.count(magazine[i]) == 0) {
            map[magazine[i]] = 1;
        } else {
            map[magazine[i]]++;
        }
    }

    for(int i = 0; i < ransom.size(); i++) {
        if(map[ransom[i]] > 0) {
            map[ransom[i]]--;
        } else {
            return false;
        }
    }

    return true;
}
