 // Given an n-element array, A = a{0}, a{1}, ..., a_{n-1}, of distinct elements, sort array A in ascending order using the Bubble Sort
 // algorithm. Once sorted, print the following three lines:

// 1 - Array is sorted in numSwaps swaps., where numSwaps is the number of swaps that took place.
// 2 - First Element: firstElement, where firstElement is the first element in the sorted array.
// 3 - Last Element: lastElement, where lastElement is the last element in the sorted array.

// Hint: To complete this challenge, you must add a variable that keeps a running tally of all swaps that occur during execution.

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


int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }

    int numSwaps = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 1; j++){
            if(a[j] > a[j+1]){
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
                numSwaps++;
            }
        }
        if(numSwaps == 0) break;
    }

    printf("Array is sorted in %i swaps.\n", numSwaps);
    printf("First Element: %i\n", a[0]);
    printf("Last Element: %i\n", a[a.size() - 1]);

    return 0;
}
