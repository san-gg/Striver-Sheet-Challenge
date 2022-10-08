#include <vector>
int recurse(string &s, string &t, int x1, int x2, vector<vector<int>> &dp) {
    if(x1 == s.length()) return 0;
    if(x2 == t.length()) return 0;
    if(dp[x1][x2] != -1) return dp[x1][x2];
    if(s[x1] == t[x2]) {
        return (dp[x1][x2] = 1 + recurse(s, t, x1 + 1, x2 + 1, dp));
    }
    else {
        int m1 = recurse(s, t, x1, x2 + 1, dp);
        int m2 = recurse(s, t, x1 + 1, x2, dp);
        dp[x1][x2] = max(m1, m2);
        return dp[x1][x2];
    } 
}
int lcs(string s, string t)
{
    vector<vector<int>> dp(s.length(), vector<int>(t.length(), -1));
    return recurse(s, t, 0, 0, dp);
}