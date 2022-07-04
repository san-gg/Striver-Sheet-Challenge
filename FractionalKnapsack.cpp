#include <algorithm>
bool cmp(pair<int, int> &x1, pair<int, int> &x2) {
    double d1 = (double)x1.second / (double)x1.first;
    double d2 = (double)x2.second / (double)x2.first;
    return d1 > d2;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(), items.end(), cmp);
    double answer = 0.0;
    for(auto &x : items) {
        if(x.first <= w) {
            answer += x.second;
            w -= x.first;
        } else if(x.first > w) {
            answer = answer + x.second * ((double)w / (double)x.first);
            break;
        }
    }
    return answer;
}