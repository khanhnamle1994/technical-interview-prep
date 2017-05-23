// Given an array of n integers and a number, d, perform d left rotations on the array.
// Then print the updated array as a single line of space-separated integers.

vector<int> array_left_rotation(vector<int> a, int n, int k) {
    k %= n;
    vector<int> vec(n);
    for(int i = 0; i < n; i++) {
        vec[(n+i-k)%n] = a[i];
    }
    return vec;
}

int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
        cin >> a[a_i];
    }
    vector<int> output = array_left_rotation(a, n, k);
    for(int i = 0; i < n;i++)
        cout << output[i] << " ";
    cout << endl;
    return 0;
}
