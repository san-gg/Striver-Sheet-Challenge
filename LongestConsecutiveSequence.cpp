#include <bits/stdc++.h> 
int lengthOfLongestConsecutiveSequence(vector<int> &arrv, int n) {
    int maxlcs = 0;
    int prev;
    set<int> arr;
    for(int x : arrv)
        arr.insert(x);
    prev = *(arr.begin());
    int cnt = 0;
    for(int x : arr) {
        if(x == prev) cnt += 1;
        else if(x != prev) {
            cnt = 1;
            prev = x;
        }
        maxlcs = max(maxlcs, cnt);
        prev += 1;
    }
    return maxlcs;
}