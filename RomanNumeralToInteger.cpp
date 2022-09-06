#include <bits/stdc++.h>
bool check(char x1, char x2) {
    if(x1 == 'I' && (x2 == 'V' || x2 == 'X')) return true;
    else if(x1 == 'X' && (x2 == 'L' || x2 == 'C')) return true;
    else if(x1 == 'C' && (x2 == 'D' || x2 == 'M')) return true;
    return false;
}
int romanToInt(string s) {
    int ans = 0;
    unordered_map<char, int> umap;
    umap['I'] = 1;   umap['V'] = 5;   umap['X'] = 10; umap['L'] = 50;
    umap['C'] = 100; umap['D'] = 500; umap['M'] = 1000;
    for(int i = 0; i < s.length(); ++i) {
        if(i+1 < s.length() && check(s[i], s[i+1])) {
            ans += (umap[s[i+1]] - umap[s[i]]);
            ++i;
        }
        else {
            ans += umap[s[i]];
        }
    }
    return ans;
}
