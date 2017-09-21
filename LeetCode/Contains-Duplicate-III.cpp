// Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute
// difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.

/* Analysis:
At the first glance, it is natural to think that "using two loops to search every two elements within distance k" to solve
this problem. However, the O(n^2) time complexity is not accepted for OJ.

Here is how I think of the problem, since it is asking for whether two indices exists ... , we have to search the array in
some way.  There are two constrains:  one is related to element values in the array, the other is related to indices.  So, we
have to consider the two at the same time when checking one pair of elements. In other words, we have to know the element value
and the element index at the same, and using some strategy, to scan the array and find if there is any pair satisfy the constrains.


Let's take an example, say the array is A = [3,6,0,4], and we set t = 2, k =2.
Let's sort the array according to the value,
the values of the array becomes:  A' = [0, 3, 4, 6]
the indices of the array becomes:  I' = [2, 0, 3, 1]
We rewrite them into one array:
P = [(0,2), (3,0), (4,3), (6,1)]

Now we are searching the pairs, starting from the first pair:
(0, 2) where 0 is the value 2 is the index.

Now we have pair  P[i] = (0,2), i = 0, we need P[j] to check if  P[i] and P[j] satisfy the constrains that
abs(P[i][0] - P[j][0]) < = t and abs(P[i][1] - P[j][1]) < = k.


When compare current pair P[0] = (0,2) and next pair P[1] = (3,0),  abs(0-3) > t. It seems natural to keep the first pair P[0] and
search the rest of array after P[1], but in fact it is not an efficient way, especially when k is a large number.

Since we have already sorted the array, if the value difference between P[0] and P[1] is greater than t, the value difference
between P[0] and P[2], P[3] ... P[end] must also greater than t. If current comparison is not satisfied, all the other comparisons
are not even necessary. We can move P[0] to next element.

While on the other hand, if the value difference <= t, but the index difference > k, we still have to  keep the current P[i] and
move P[j] until meets the above scenario or the end of the array.

In this example:
1. Compare (0,2) and (3,0),   abs(0-3) >t
2. Compare (3,0) and (4,3),   abs(3-4) <=t , abs(0-3) > k
3. Compare (3,0) and (6,1),   abs(6-3) > t
4..Compare (4,3) and (6,1),   abs(4-6) <=t, abs(3-1)<=k, satisfied. Return True.
*/

static bool pcomp(pair<int,int> a, pair<int,int> b) {
    return a.first < b.first ;
}

bool search(vector<pair<int,int> > l, int t, int k){
    int po = 0;
    while (po < l.size()){
        int i = po + 1;
        while (i < l.size()){
            if ((abs(long(l[i].first) - long(l[po].first)) <= t)&&(abs(l[i].second - l[po].second)<= k)){
                return true;
            } else {
                if (abs(long(l[i].first) - long(l[po].first)) > t){
                    break;
                } else {
                    i += 1;
                }
            }
        }
        po += 1;
    }
    return false;
}

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    if (nums.size() == 0 ){
        return false;
    }
    vector<pair<int,int> > pp;
    for (int i=0;i<nums.size();i++){
        pp.push_back(make_pair(nums[i], i));
    }
    sort(pp.begin(),pp.end(),pcomp);
    return search(pp, t, k);
}
