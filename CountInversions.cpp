#include <bits/stdc++.h>

long long mergeSort(long long *arr, int i, int j, vector<long long> &tmp) {
    if(i >= j) return 0;
    int k = i + (j - i) / 2;
    long long c1 = mergeSort(arr, i, k, tmp);
    long long c2 = mergeSort(arr, k+1, j, tmp);
    long long c3 = 0;
    int i1 = k+1;
    int pos = i;
    int x = i, y = j;
    while(i <= k && i1 <= j) {
        if(arr[i] < arr[i1]) {
            tmp[pos] = arr[i];
            ++i;
        }
        else {
            c3 += k - i + 1;
            tmp[pos] = arr[i1];
            ++i1;
        }
        ++pos;
    }
    while(i <= k) tmp[pos++] = arr[i++];
    while(i1 <= j) tmp[pos++] = arr[i1++];
    while(x <= y) {
        arr[x] = tmp[x];
        ++x;
    }
    return c3 + c1 + c2;
}

long long getInversions(long long *arr, int n) {
    vector<long long> tmp(n, 0);
    long long ans = mergeSort(arr, 0, n-1, tmp);
    return ans;
}