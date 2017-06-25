// Comparators are used to compare two objects. In this challenge, you'll create a comparator and use it to sort an array.
// The Player class is provided in the editor below; it has two fields:
// 1 - A string, name.
// 2 - An integer, score.

// Given an array of n Player objects, write a comparator that sorts them in order of decreasing score; if 2 or more players
// have the same score, sort those players alphabetically by name.

#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct Player {
    string name;
    int score;
};

bool compareStrings(string a, string b){
    int index = 0;
    while(a[index] == b[index])
        index++;
    return a[index] < b[index];
}

bool comparator (Player p1, Player p2) {
    if(p1.score != p2.score) {
        return (p1.score > p2.score);
    } else {
        return compareStrings(p1.name, p2.name);
    }
}

int main() {

    int n;
    cin >> n;
    vector< Player > players;
    string name;
    int score;
    for(int i = 0; i < n; i++){
        cin >> name >> score;
        Player p1;
        p1.name = name, p1.score = score;
        players.push_back(p1);
    }

    sort(players.begin(), players.end(), comparator);

    for(int i = 0; i < players.size(); i++) {
        cout << players[i].name << " " << players[i].score << endl;
    }
    return 0;
}
