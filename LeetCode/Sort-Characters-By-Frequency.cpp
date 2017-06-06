// Given a string, sort it in decreasing order based on the frequency of characters.

/* Analysis:
+ Use an unordered_map to store the frequency of each char. The key is the character and the value is the frequency.
+ Use one more map. The key is the frequency and the value is a vector<string> to store characters. The reason to use vector<string> to
store characters is that there might be more than one character have the same frequency. And the reason to use one more map is that map
will sort the data in increasing order based on key. Therefore, the highest frequent character will be the last element of map.
+ Append all the characters to the string according their frequency. */


class Solution {
public:
    string frequencySort(string s) {
        string ansStr;

        unordered_map<char,int> freqMap;
        map<int,vector<char>> ansMap;

        //> count frequenct of character in string
        for(auto c : s) {
            freqMap[c]++;
        }

        //> put to Map : key is frequency, value is character
        //> Map will sort key automatically (increasing order)
        for(auto f : freqMap) {
            ansMap[f.second].push_back(f.first);
        }

        //> append character to string depends on its frequency
        for(auto it = ansMap.rbegin(); it != ansMap.rend(); ++it) {
            for(auto c : it->second) {
                ansStr.append(it->first, c);
            }
        }

        return ansStr;
    }
};
