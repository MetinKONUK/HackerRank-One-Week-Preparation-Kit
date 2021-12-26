int lonelyinteger(vector<int> a) {
    int result = a[0];
    for(int i = 1; i < a.size(); ++i)
        result ^= a[i];
    return result;
}
