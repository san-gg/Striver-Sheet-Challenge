#include <bits/stdc++.h>
bool isPalindrome(string &str, int x1, int x2) {
    while(x1 < x2) {
        if(str[x1++] != str[x2--]) return false;
    }
    return true;
}
int recurse(string &str, vector<int> &dp, int pos) {
    int n = str.length();
    if(pos == n) return 0;
    if(dp[pos] != -1) return dp[pos];
    int minVal = INT_MAX;
    int x = pos;
    while(x < n) {
        if(str[pos] == str[x] && isPalindrome(str, pos, x)) {
            minVal = min(minVal, recurse(str, dp, x+1) + 1);
        }
        x += 1;
    }
    minVal = min(minVal, n-pos);
    return dp[pos] = minVal;
}
int palindromePartitioning(string str) {
    vector<int> dp(str.length(), -1);
    return recurse(str, dp, 0)-1;
}
