#include <cmath>
typedef long long ull;
ull createHash(const string &str) {
    long prime = 3;
    long len = str.length() - 1;
    ull hash = 0;
    for(char c : str) {
        hash += (ull)c;
    }
    return hash;
}

bool check(string &pat, string &str, int x) {
    int i = 0;
    int len2 = pat.length();
    int len1 = str.length();
    while(x < len1 && i < len2) if(str[x++] != pat[i++]) break;
    if(i == len2) return true;
    return false;
}

vector<int> stringMatch(string &str, string &pat) {
    // Rolling Hash
    vector<int> ans;
    ull patHash = createHash(pat);
    long patlen = pat.length();
    if(str.length() < patlen) return {};
    ull currHash = createHash(str.substr(0, patlen));
    if(currHash == patHash && check(pat, str, 0)) ans.push_back(0);
    
    int x = 1;
    for(int i = patlen--; i < str.length(); i++) {
        currHash -= (ull)str[x-1];
        currHash = currHash + (ull)str[i];
        if(currHash == patHash && check(pat, str, x)) ans.push_back(x);
        ++x;
    }
    return ans;
}
