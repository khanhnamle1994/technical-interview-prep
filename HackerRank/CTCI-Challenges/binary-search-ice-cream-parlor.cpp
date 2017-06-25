// Each time Sunny and Johnny take a trip to the Ice Cream Parlor, they pool together money dollars for ice cream. On any given day,
// the parlor offers a line of n flavors. Each flavor, , is numbered sequentially with a unique ID number from 1 to n and has a cost,
// cost_i , associated with it.

// Given the value of money and the cost of each flavor for t trips to the Ice Cream Parlor, help Sunny and Johnny choose two distinct
// flavors such that they spend their entire pool of money during each visit. For each trip to the parlor, print the ID numbers for the
// two types of ice cream that Sunny and Johnny purchase as two space-separated integers on a new line. You must print the smaller ID
// first and the larger ID second.

// Note: Two ice creams having unique IDs  and  may have the same cost (i.e., ).

#include <bits/stdc++.h>
using namespace std;

class IceCream {

    public:
        int flavor;
        int index;

        IceCream(int f, int i) {
            flavor = f;
            index = i;
       }
};

struct {
    bool operator()(IceCream a, IceCream b) const {
        return a.flavor < b.flavor;
    }
} compare;

int binarySearch(int first, int last, vector<IceCream> arr, int search)
{
   if (last >= first)
   {
        int mid = first + (last - first)/2;

        // If the element is present at the middle itself
        if (arr[mid].flavor == search)  return mid;

        // If element is smaller than mid, then it can only be present
        // in left subarray
        if (arr[mid].flavor > search) return binarySearch(first, mid-1, arr, search);

        // Else the element can only be present in right subarray
        return binarySearch(mid+1, last, arr, search);
   }

   // We reach here when element is not present in array
   return -1;
}

int main() {
    int t;
    int n, m;
    cin >> t;
    for(int test = 0; test < t; test++) {
        cin >> m >> n;
        vector<IceCream> arr;
        arr.reserve(n);

        for (int i = 0; i < n; i++) {
            int cost;
            cin >> cost;
            arr.push_back(IceCream(cost, i + 1));
        }

        sort(arr.begin(), arr.end(), compare);

        int firstIndex = 100000, secondIndex = 100000;
        for(int i = 0; i < n - 1 ; i++) {
            int search = m - arr[i].flavor;
            if(search >= arr[i].flavor) {
                int index = binarySearch( i + 1, n - 1, arr, search);
                if( index != -1 ) {
                    if (arr[i].index < arr[index].index)
                        cout << arr[i].index << " " << arr[index].index << endl;
                    else
                        cout << arr[index].index << " " << arr[i].index << endl;
                    break;

                }
            }
        }

    }

}
