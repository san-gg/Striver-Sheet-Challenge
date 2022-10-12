#include <bits/stdc++.h>
typedef vector<int> vi;
int recurse(string &str1, string &str2, vector<vi> &dp, int x1, int x2) {
    if(x1 == -1) return x2+1;
    if(x2 == -1) return x1+1;
    if(dp[x1][x2] != -1) return dp[x1][x2];
    if(str1[x1] == str2[x2]) {
        return dp[x1][x2] = recurse(str1, str2, dp, x1-1, x2-1);
    }
    int m = min(recurse(str1, str2, dp, x1, x2-1), recurse(str1, str2, dp, x1-1, x2-1));
    m = min(m, recurse(str1, str2, dp, x1-1, x2));
    dp[x1][x2] = m + 1;
    return m+1;
}

int editDistance(string str1, string str2)
{
    vector<vector<int>> dp(str1.length(), vector<int>(str2.length(),-1));
    int x = recurse(str1, str2, dp, str1.length()-1, str2.length()-1);
    return x;
}