// A left rotation operation on an array of size n shifts each of the array's elements 1 unit to the left. For example, if 2 left
// rotations are performed on array [1,2,3,4,5], then the array would become [3,4,5,1,2].

// Given an array of n integers and a number, d, perform d left rotations on the array. Then print the updated array as a single line
// of space-separated integers.

// First Solution: Rotate in-place
vector<int> array_left_rotation(vector<int> a, int n, int k) {
    for (int i = 1; i <= k; i++) {
        int temp = a[0];
        for(int j = 0; j < n - 1; j++) {
            a[j] = a[j + 1];
        }
        a[n - 1] = temp;
    }
    return a;
}

// Second Solution: Create a new array then insert integers into the right index
vector<int> array_left_rotation(vector<int> a, int n, int k) {
    vector<int> new_array(n);
    for(int i = 0; i < n; i++) {
        new_array[(i - k + n) % n] = a[i];
    }
    return new_array;
}
