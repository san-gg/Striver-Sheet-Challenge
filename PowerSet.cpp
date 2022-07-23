#include <algorithm>
vector<vector<int>> pwset(vector<int>v) {
    sort(v.begin(), v.end());
    int choose = 0;
    vector<vector<int>> answer;
    int maxVal = pow(2, v.size()) - 1;
    while(choose <= maxVal) {
        vector<int> arr;
        int go = choose;
        int x = 0;
        while(go != 0) {
            if(go & 1)
                arr.push_back(v[x]);
            ++x;
            go = go >> 1;
        }
        answer.push_back(arr);
        ++choose;
    }
    return answer;
}