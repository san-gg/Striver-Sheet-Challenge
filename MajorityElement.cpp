#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
	unordered_map<int,int> m;
    for(int i = 0; i < n; i++)
        m[arr[i]]++;
    int f = floor(n / 2);
    int mE = -1;
    for(auto &x : m) {
        if(x.second > f) {
            mE = x.first;
            break;
        }
    }
    return mE;
}