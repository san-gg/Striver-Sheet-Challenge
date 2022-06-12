#include <bits/stdc++.h> 
string fourSum(vector<int> arr, int target, int n) {
    unordered_map<int, pair<int, int>> umap;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++)
            umap[arr[i] + arr[j]] = {i, j};
    }
    auto ed = umap.end();
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int sum1 = arr[i] + arr[j];
            auto p = umap.find(target - sum1);
            if(p != ed) {
                auto &sum2 = p->second;
                if(i != sum2.first && i != sum2.second && j != sum2.first
                  && j != sum2.second) {
                    return "Yes";
                }
            }
        }
    }
    return "No";
}