#include <bits/stdc++.h> 
using namespace std;
vector<vector<long long int>> printPascal(int n) {
    vector<vector<long long int>> answer(n,vector<long long int>());
    answer[0].push_back(1);
    for(int i = 1; i < n; i++) {
        auto &p = answer[i - 1];
        int sz = p.size();
        answer[i].push_back(1);
        for(int j = 1; j < sz; j++)
            answer[i].push_back(p[j] + p[j - 1]);
        answer[i].push_back(1);
    }
    return answer;
}
