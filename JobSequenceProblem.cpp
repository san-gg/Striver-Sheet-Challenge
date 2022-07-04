#include <algorithm>
int jobScheduling(vector<vector<int>> &jobs) {
    int maxTime = 1;
    for(auto &x : jobs) {
        maxTime = max(maxTime, x[0]);
        swap(x[0],x[1]);
    }
    sort(jobs.begin(), jobs.end());
    int indx = jobs.size()- 1;
    vector<int> vec(maxTime, 0);
    while(indx >= 0) {
        auto &v = jobs[indx];
        if(vec[v[1] - 1] == 0) {
            vec[v[1] - 1] = v[0];
        }
        else {
            int x = v[1] - 1;
            while(x >= 0) {
                if(vec[x] == 0) {
                    vec[x] = v[0];
                    break;
                }
                --x;
            }
        }
        --indx;
    }
    int maxProfit = 0;
    for(int x : vec)  maxProfit += x;
    return maxProfit;
}
