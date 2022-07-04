#include <algorithm>

bool cmp(pair<int, int> &x1, pair<int, int> &x2) {
    return x1.second < x2.second;
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    vector<pair<int, int>> val;
    for(int i = 0; i < start.size(); i++) {
        val.push_back({start[i], finish[i]});
    }
    sort(val.begin(), val.end(), cmp);
    int prev = -1;
    int activities = 0;
    for(auto &x : val) {
        if(prev <= x.first) {
            ++activities;
            prev = x.second;
        }
    }
    return activities;
}