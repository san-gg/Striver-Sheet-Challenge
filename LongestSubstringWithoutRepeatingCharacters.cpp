#include <bits/stdc++.h> 
int uniqueSubstrings(string input) {
    int arr1[27] = {0};
    int arr2[27] = {0};
    int x = 0;
    int n = 0;
    int maxUnique = 0;
    for(char c : input) {
        if(arr1[c - 'a']) {
            int pos = arr2[c - 'a'] + 1;
            maxUnique = max(maxUnique, n - x);
            while(x < pos) {
                arr1[input[x] - 'a'] = 0;
                arr2[input[x] - 'a'] = 0;
                ++x;
            }
        }
        arr1[c - 'a'] = 1;
        arr2[c - 'a'] = n;
        ++n;
    }
    maxUnique = max(maxUnique, n - x);
    return maxUnique;
}