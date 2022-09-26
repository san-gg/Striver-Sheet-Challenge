#include <bits/stdc++.h>

int getMid(int mid, vector<int> &v, int data) {
    if(mid == -1) {
        v.push_back(data);
        return 0;
    }
    mid = (v.size()+1) / 2;
    if((v.size()+1) % 2 == 0)
        mid -= 1;
    auto itr = lower_bound(v.begin(), v.end(), data);
    v.insert(itr, data);
    return mid;
}

vector<int> findMedian(vector<int> &arr, int n){
    vector<int> ans;
    vector<int> v;
    int mid = -1;
    for(int i = 0; i < n; i++) {
        mid = getMid(mid, v, arr[i]);
        if((i+1) % 2 == 0)
            ans.push_back(floor((v[mid] + v[mid+1]) / 2));
        else ans.push_back(v[mid]);
    }
    return ans;
}
