#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n) {
    long long maxSum = arr[0];
    long long sums = arr[0] < 0 ? 0 : arr[0];
    bool allNegative = true;
    for(int i = 1; i < n; i++) {
        if(arr[i] > 0) {
            allNegative = false;
            break;
        }
    }
    if(allNegative) return 0;
    if(n == 1) return maxSum;
    for(int i = 1; i < n; i++) {
        sums += arr[i];
        maxSum = max(maxSum, sums);
        if(sums < 0) sums = 0;
    }
    return maxSum;
}