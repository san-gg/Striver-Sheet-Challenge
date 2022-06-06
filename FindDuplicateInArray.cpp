#include <bits/stdc++.h> 
int findDuplicate(vector<int> &arr, int n) {
    int arr1[100000] = {0};
    for(int x : arr) {
        if(arr1[x - 1] == x) return x;
        arr1[x - 1] = x;
    }
    return 0;
}