#include <bits/stdc++.h> 
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    vector<int> ans;
    unordered_map<int, int> um;
    int sz = arr.size();
    int x = 0;
    for(int i = 0; i < k; i++) um[arr[i]]++;
    ans.push_back(um.size());
    while(k < sz) {
        if(--um[arr[x]] == 0) um.erase(arr[x]);
        um[arr[k]]++;
        ans.push_back(um.size());
        k += 1;
        x += 1;
    }
    return ans;
}
