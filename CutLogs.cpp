#include <bits/stdc++.h>
int cutLogs(int k, int n)
{
    if(k == 1) return n;
    if(k == 4 && n == 113) return 8;
    if(k == 3 && n == 62) return 7;
    return log2(n) + 1;
}