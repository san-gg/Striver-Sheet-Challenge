#include <bits/stdc++.h> 
typedef vector<int> vi;

int recurse(vi &arr, int N, vector<vi> &dp, int start, int end) {
    if(dp[start][end] != INT_MAX) return dp[start][end];
    int minVal = INT_MAX;
    for(int part = start + 1; part < end; ++part) {
        int x1 = 0;
        if(start + 1 != part) x1 = x1 + recurse(arr, N, dp, start, part);
        if(part + 1 != end) x1 = x1 + recurse(arr, N, dp, part, end);
        int x2 = x1 + (arr[start] * arr[part] * arr[end]);
        minVal = min(minVal, x2);
    }
    dp[start][end] = minVal;
    return minVal;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vi> dp(N, vi(N, INT_MAX));
    recurse(arr, N, dp, 0, N-1);
    return dp[0][N-1];
}