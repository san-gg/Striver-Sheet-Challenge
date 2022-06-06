#include <bits/stdc++.h> 
#include <vector>

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    for(int i = 0; i < m; ++i) {
        if(binary_search(mat[i].begin(), mat[i].end(), target))
            return true;
    }
    return false;
}