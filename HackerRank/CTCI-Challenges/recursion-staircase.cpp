// Davis has s staircases in his house and he likes to climb each staircase 1, 2, or 3 steps at a time. Being a very precocious child,
// he wonders how many ways there are to reach the top of the staircase.

// Given the respective heights for each of the s staircases in his house, find and print the number of ways he can climb each
// staircase on a new line.

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int cache[37];

int steps(int n){
    if(n < 0) return 0;
    if(cache[n]) return cache[n];
    else return cache[n] = steps(n-1) + steps(n-2) + steps(n-3);
}

int main(){
    int s, n;
    cache[0] = 1;
    std::cin >> s;
    while(s--){
        std::cin >> n;
        std::cout << steps(n) << std::endl;
    }
    return 0;
}
