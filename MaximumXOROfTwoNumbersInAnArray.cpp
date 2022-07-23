#include <bits/stdc++.h>
int maximumXor(vector<int> A)
{
    int ans = 0;
    int prefix = 0;
    for(int i = 31; i >= 0; i--) {
        // Fill MSB to LSB to 1 - to find max element
        prefix |= (1 << i);
        unordered_set<int> us;
        // 1] Turning point - get largest number peak value eg. 001010 -> 001000
        // 2] keep adding largest numbers peak values
        for(int x : A) {
            us.insert(x & prefix);
        }
        
        // 1] based on test data - loop until u get largest number peak value
        // 2] ans | (1 << i) eventually largest element in A will be found in us.
        int c = ans | (1 << i);
        for(int x : us) {
            int e = x ^ c;
            if(us.find(e) != us.end()) {
                // 3] keep updating ans - iterate again via peaked largest number value.
                ans = c;
                break;
            }
        }
    }
    return ans;
}