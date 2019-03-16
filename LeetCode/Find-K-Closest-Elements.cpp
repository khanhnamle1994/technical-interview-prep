/* Given a sorted array, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

Example 1:
Input: [1,2,3,4,5], k=4, x=3
Output: [1,2,3,4]

Example 2:
Input: [1,2,3,4,5], k=4, x=-1
Output: [1,2,3,4] */

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int l = 0;
    for (int i = k; i < arr.size(); ++i) if (arr[i] < x || abs(arr[i] - x) < abs(arr[l] - x)) ++l; else break;
    return vector<int>(begin(arr) + l, begin(arr) + l + k);
}
