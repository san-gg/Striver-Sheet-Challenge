#include <algorithm>
#include <queue>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
    priority_queue<int> less;
    priority_queue<int, vector<int>, greater<int>> greater;
    vector<int> vec;
    for(int val : arr) {
        less.push(val);
        greater.push(val);
        if(less.size() > k) {
            less.pop();
            greater.pop();
        }
    }
    vec.push_back(less.top());
    vec.push_back(greater.top());
    return vec;
}