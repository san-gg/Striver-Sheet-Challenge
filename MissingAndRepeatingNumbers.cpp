#include <bits/stdc++.h>
pair<int,int> missingAndRepeating(vector<int> &arr, int n) {
    int sum = 0;
    int actualSum = n * (n + 1) / 2;
    int M, R;
    for(int x : arr) {
        x = abs(x);
        if(arr[x - 1] < 0) {
            R = x;
            continue;
        }
        sum += x;
        arr[x - 1] = -arr[x - 1];
    }
    M = actualSum - sum;
    return {M,R};
}
