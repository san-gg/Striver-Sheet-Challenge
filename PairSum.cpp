#include <bits/stdc++.h> 
vector<vector<int>> pairSum(vector<int> &arr, int s){
    map<int, int> umap;
    vector<vector<int>> answer;
    for(int x : arr) {
        umap[x]++;
    }
    for(auto &p : umap) {
        int x1 = umap[s - p.first];
        int x2 = p.second;
        if(x1) {
            p.second = 0;
            int no = x1 * x2;
            if(p.first == s - p.first) {
                no = x1 * (x1 - 1) / 2;
            }
            while(no) {
                answer.push_back({p.first, s-p.first});
                --no;
            }
        }
    }
    return answer;
}