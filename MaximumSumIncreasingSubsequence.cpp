#include <bits/stdc++.h> 
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	int sz = rack.size();
    int m = 0;
    vector<int> dp(rack);
    for(int i = 0; i < sz; i++) {
        m = max(dp[i], m);
        for(int j = i+1; j < sz; j++) {
            if(rack[i] < rack[j]) {
                dp[j] = max(dp[j], dp[i] + rack[j]);
                m = max(dp[j], m);
            }
        }
    }
    return m;
}