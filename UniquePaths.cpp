#include <bits/stdc++.h>
/*
int bruteForce(int x, int y, int m, int n) {
    int cnt = 0;
    if((x == m - 1) && (y == n - 1)) return 1;
    if(y == n || x == m) return 0;
    cnt += bruteForce(x, y+1, m, n);
    cnt += bruteForce(x+1, y, m, n);
    cout << "(" << x << ", " << y << ") => " << cnt << endl;
    return cnt;
}
*/
int uniquePaths(int m, int n) {
    int ans = 0;
    vector<int> val(m, 1);
    for(int i = 1; i < n; i++) {
        int x = m - 1;
        while(x >= 1) {
            val[x - 1] = val[x - 1] + val[x];
            --x;
        }
    }
    return val[0];
}