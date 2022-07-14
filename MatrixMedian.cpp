#include <set>
int getMedian(vector<vector<int>> &matrix) {
    multiset<int> ms;
    for(auto &x : matrix) {
        for(int i : x) {
            ms.insert(i);
        }
    }
    vector<int> fv(ms.begin(), ms.end());
    return fv[fv.size()/2];
}