#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x) {
    unordered_map<int, int> umap;
    int s = 0;
    int count = 0;
    for(int i : arr) {
        s = s ^ i;
        auto p = umap.find(s ^ x);
        if(p != umap.end()) {
            count += p->second;
        }
        if(s == x) {
            ++count;
        }
        umap[s]++;
    }
    return count;
}