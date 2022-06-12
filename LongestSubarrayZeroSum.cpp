#include <bits/stdc++.h> 
int LongestSubsetWithZeroSum(vector < int > arr) {
    int sz = arr.size();
    int maxLen = 0;
    for(int i = 0; i < sz; i++) {
        int sum = arr[i];
        if(sum == 0) maxLen = max(maxLen, 1);
        for(int j = i+1; j < sz; j++) {
            sum += arr[j];
            if(sum == 0)
                maxLen = max(maxLen, j - i + 1);
        }
    }
    return maxLen;
}