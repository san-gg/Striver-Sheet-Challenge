#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &arr) {
    unordered_map<int,int> m;
    vector<int> answer;
    int n = arr.size();
    for(int i = 0; i < n; i++)
        m[arr[i]]++;
    int f = floor(n / 3);
    for(auto &x : m) {
        if(x.second > f)
            answer.push_back(x.first);
    }
    return answer;
}