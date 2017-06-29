// Given a dictionary, write a functio that returns a flattened version of it

#include <iostream>
#include <unordered_map>

using namespace std;

vector<unordered_map<string, void*>> flattenDictionary(unordered_map<string, void*>& dict) {
  unordered_map<string, void*> flatDictionary;
  flattenDictionaryHelper("", dict, flatDictionary);

  return flatDictionary;
}

vector<vector<int>> flattenDictionaryHelper(string& initialKey, unordered_map<string, void*>& dict, 
  unordered_map<string, void*>& flatDictionary) {

}
