#include <bits/stdc++.h> 
int modularExponentiation(int x1, int n, int m) {
    unsigned long res = 1;
    unsigned long x = 0;
    x = x1;
    while(n) {
        if(n & 1) {
            res = (res % m * x % m) % m;
        }
        x = (x % m * x % m) % m;
        n = n >> 1;
    }
    return res % m;
}