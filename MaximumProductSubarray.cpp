#include <bits/stdc++.h> 
int maximumProduct(vector<int> &arr, int n)
{
    int maxProd = arr[0];
    int x_max = arr[0];
    int x_min = arr[0];
    for(int i = 1; i < n; i++) {
        int tmp = x_max;
        x_max = max(arr[i], max(x_min * arr[i], x_max * arr[i]));
        x_min = min(arr[i], min(x_min * arr[i], tmp * arr[i]));
        maxProd = max(x_max, maxProd);
    }
    return maxProd;
}
