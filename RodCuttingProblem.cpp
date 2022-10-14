#include <vector>
int recurse(vector<int> &price, int n, vector<vector<int>> &dp, int pieces, int pos) {
    if(pieces < 0) return -1;
    if(pos > n || pieces == 0) return 0;
    if(dp[pos][pieces] != -1) return dp[pos][pieces];
    int cut = recurse(price, n, dp, pieces-pos, pos);
    int noCut = recurse(price, n, dp, pieces, pos+1);
    cut = (cut == -1) ? 0 : (cut+price[pos-1]);
    int x = max(cut, noCut);
    return dp[pos][pieces] = x;
}
int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return recurse(price, n, dp, n, 1);
}
