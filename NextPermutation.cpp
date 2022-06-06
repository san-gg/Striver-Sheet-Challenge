#include <bits/stdc++.h>
void swapsArr(vector<int> &permutation, int n1, int n2) {
    while(n1 < n2) {
        swap(permutation[n1], permutation[n2]);
        n1 += 1;
        n2 -= 1;
    }
}
vector<int> nextPermutation(vector<int> &permutation, int n) {
    int x1 = n - 2;
    int x2 = n - 1;
    if(n == 1) return permutation;
    if((n == 2) || (permutation[x1] < permutation[x2])) {
        swap(permutation[x1], permutation[x2]);
        return permutation;
    }
    while(x1 >= 0) {
        if(permutation[x1] < permutation[x1 + 1])
            break;
        --x1;
    }
    if(x1 == -1) {
        swapsArr(permutation, 0, x2);
    } else if(permutation[x1] < permutation[x1 + 2]) {
        swapsArr(permutation, x1 + 1, x2);
        swap(permutation[x1], permutation[x1 + 1]);
    }
    else {
        swap(permutation[x1], permutation[x1 + 1]);
        swapsArr(permutation, x1 + 1, x2);
    }
    
    return permutation;
}