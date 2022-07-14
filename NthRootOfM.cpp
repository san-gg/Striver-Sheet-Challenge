long double power(long double mid, int n){
    long double ans = 1.0;
    while(n--)
        ans *= mid;
    return ans;
}

long double findNthRootOfM(int n, long long m) {
    long double low = 1.00;
    long double high = m;
    long double mx = 1e-9;
    while((high - low) > mx) {
        long double mid = low + (high-low) / 2.0;
        if(power(mid, n) < m) {
            low = mid;
        }else {
            high = mid;
        }
        cout << low << "  " << high << endl;
    }
    return low;
}