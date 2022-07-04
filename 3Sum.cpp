#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
    vector<vector<int>> answer;
    sort(arr.begin(), arr.end());
    
    for(int i = 0; i < n; i++) {
        int l = i + 1;
        int r = n - 1;
        while(l < r) {
            if(arr[i] + arr[l] + arr[r] == K) {
                answer.push_back({arr[i], arr[l], arr[r]});
                int x = arr[l];
                while(l < r && x == arr[l]) ++l;
                x = arr[r];
                while(l < r && x == arr[r]) --r;
            }
            else if (arr[i] + arr[l] + arr[r] < K) {
                ++l;
            } else {
                --r;
            }
        }
        while(i + 1 < n && arr[i] == arr[i+1]) {
            ++i;
        }
    }
    return answer;
}