void miniMaxSum(vector<int> arr) {
    sort(arr.begin(), arr.end());

    long int max_sum = 0, min_sum = 0;
    for(int i = 4; i > 0; i--) {
        max_sum += arr[i];
    }
    for(auto i = 0; i < 4; i++) {
        min_sum += arr[i];
    }
    cout << min_sum << " " << max_sum;
}
