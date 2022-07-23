#include <bits/stdc++.h>
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
    sort(arr.begin(), arr.end());
    vector<int> answer;
    for(auto &p : queries) {
        int ans = -1;
        for(int x : arr) {
            if(x > p[1]) break;
            ans = max(ans, x ^ p[0]);
        }
        answer.push_back(ans);
    }
    return answer;
}