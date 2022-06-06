#include <bits/stdc++.h> 
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    int pos = arr1.size() - 1;
    n -= 1;
    m -= 1;
    while(n >= 0) {
        if(arr1[m] <= arr2[n]) {
            arr1[pos] = arr2[n];
            --pos;
            --n;
        }
        else if(arr1[m] > arr2[n]) {
            arr1[pos] = arr1[m];
            arr1[m] = 0;
            --pos;
            --m;
        }
    }
    return arr1;
}