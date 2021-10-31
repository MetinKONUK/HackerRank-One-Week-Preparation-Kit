void plusMinus(vector<int> arr) {
    double positive = 0, negative = 0, zero = 0;
    for(int i = 0; i < arr.size(); ++i) {
        if(arr[i] > 0) {
            positive++;
        } else if(arr[i] < 0) {
            negative++;
        } else {
            zero++;
        }
    }
    int x = arr.size();
    std::cout << setprecision(6) << positive / x << std::endl
     << negative / x << std::endl
     << zero / x;
}
