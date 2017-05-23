// Given an array, A, of N integers, print each element in reverse order as a single line of space-separated integers.

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++){
       cin >> arr[i];
    }

    for(int i = n - 1; i > 0; i--){
        cout << arr[i];
        cout << " ";
    }

    cout << arr[0];

    return 0;
}
