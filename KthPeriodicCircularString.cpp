//Initial Template for C++
// GFG
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    string kPeriodic(string s, int K) {
        int len = s.length();
        
        map<char, int> val;
        string ans(s.length(),'\0');
        for(char c : s) val[c]++;
        int x = K % len;
        int pos = 0;
        auto p = val.begin();
        while(pos < len) {
            if(ans[pos] == '\0') {
                if(p->second == 0) p++;
                int i = pos;
                char chr = p->first;
                int freq = p->second;
                while(ans[i] != chr && ans[i] == '\0') {
                    if(freq == 0) return string();
                    ans[i] = chr;
                    --freq;
                    i = (i + x) % len;
                }
                if(ans[i] != chr && freq != 0)
                    return string();
                p->second = freq;
            }
            ++pos;
        }

        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        int K;
        cin >> K;
        Solution obj;
        string ans = obj.kPeriodic(s, K);
        if(ans.length() == 0){
            cout << "-1\n";
        }
        else{
            cout << ans << "\n";
        }
    }
}  // } Driver Code Ends