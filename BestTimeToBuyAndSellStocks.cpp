#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices) {
    int sz = prices.size();
    int doBuy = prices[0];
    int maxMoney = 0;
    for(int i = 1; i < sz; i++) {
        if(doBuy > prices[i]) {
            doBuy = prices[i];
            continue;
        }
        maxMoney = max(maxMoney, prices[i] - doBuy);
    }
    return maxMoney;
}