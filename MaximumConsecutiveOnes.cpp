#include <deque>
int longestSubSeg(vector<int> &arr , int n, int k) {
    int maxOne = 0;
    int x = 0;
    deque<int> qds;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == 1) {
            x += 1;
        }
        else if(arr[i] == 0 && k != 0) {
            --k;
            x += 1;
            qds.push_back(i);
        }
        else {
            qds.push_back(i);
            x = i - qds.front();
            qds.pop_front();
        }
        maxOne = max(maxOne, x);
    }
    maxOne = max(maxOne, x);
    return maxOne;
}
