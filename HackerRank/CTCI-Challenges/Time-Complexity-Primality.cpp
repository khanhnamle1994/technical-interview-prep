// A prime is a natural number greater than 1 that has no positive divisors other than 1 and itself. Given p integers, determine the
// primality of each integer and print whether it is Prime or Not prime on a new line.

// Note: If possible, try to come up with an O(sqrt(n)) primality algorithm, or see what sort of optimizations you can come up with
// for an O(n) algorithm.

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

bool isPrime(int n) {
    for(int i = 2; i <= sqrt(n); i++) {
        if(n%i == 0) return false;
    }
    return true;
}

int main(){
    int p;
    cin >> p;
    for(int a0 = 0; a0 < p; a0++){
        int n;
        cin >> n;

        if(n >= 2 && isPrime(n)) {
            cout << "Prime" << endl;
        } else {
            cout << "Not prime" << endl;
        }
    }

    return 0;
}
