#include <bits/stdc++.h> 
bool recurse(int pos, int n, int k, vector<int> &arr, vector<vector<int>> &dp) {
    if(k == 0) return true;
    if(pos == n || k < 0) return false;
    if(dp[pos][k] != -1) return dp[pos][k];
    bool noTake = recurse(pos+1, n, k, arr, dp);
    bool take = recurse(pos+1, n, k-arr[pos], arr, dp);
    return dp[pos][k] = noTake || take;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    return recurse(0, n, k, arr, dp);
}