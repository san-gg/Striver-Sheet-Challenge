#include <vector>
typedef vector<int> vi;

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    vector<int> dp(w+1, 0);
    for(int i = 1; i < n+1; i++) {
        for(int j = w; j >= weights[i-1]; j--) {
            dp[j] = max(values[i-1] + dp[j - weights[i-1]], dp[j]);
        }
    }
    return dp[w];
}