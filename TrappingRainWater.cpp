#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    int left = 0;
    int right = n - 1;
    long sum = 0;
    while(left + 1 < n) {
        if(arr[left] > arr[left+1]) break;
        ++left;
    }
    while(right - 1 > 0) {
        if(arr[right] > arr[right-1]) break;
        --right;
    }
    long xL = arr[left];
    long xR = arr[right];
    while(left < right) {
        if(arr[left] <= arr[right]) {
            xL = max(xL, arr[left]);
            sum = sum + xL - arr[left];
            ++left;
        }
        else if(arr[left] > arr[right]) {
            xR = max(xR, arr[right]);
            sum = sum + xR - arr[right];
            --right;
        }
    }
    
    return sum;
}