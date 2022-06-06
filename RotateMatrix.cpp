#include <bits/stdc++.h> 

void rotateMatrix(vector<vector<int>> &mat, int n, int m) {
    int r1 = 0;
    int r2 = n - 1;
    int c1 = 0;
    int c2 = m - 1;
    while(r1 < r2 && c1 < c2) {
        int tmp = mat[r1].at(c1);
        int x = c1 + 1;
        while(x <= c2) {
            swap(mat[r1].at(x), tmp);
            x += 1;
        }
        x = r1 + 1;
        while(x <= r2) {
            swap(mat[x].at(c2), tmp);
            x += 1;
        }
        x = c2 - 1;
        while(x >= c1) {
            swap(mat[r2].at(x), tmp);
            x -= 1;
        }
        x = r2 - 1;
        while(x >= r1) {
            swap(mat[x].at(c1), tmp);
            x -= 1;
        }
        r1 += 1;
        c1 += 1;
        r2 -= 1;
        c2 -= 1;
    }
}