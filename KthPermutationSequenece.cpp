int fact(int n) {
     return (n==0) || (n==1) ? 1 : n* fact(n-1);
}
string kthPermutation(int n, int k) {
    string pre;
    string finalString;
    int x = 1, f, y;
    while(x <= n) {
        pre.append(1,'0'+x);
        ++x;
    }
    f = y = 0;
    int pos = 0;
    while(n) {
        n = n - 1;
        f = fact(n);
        while(y+f < k) {
            y += f;
            ++pos;
        }
        finalString.append(1,pre[pos]);
        pre.erase(pos, 1);
        pos = 0;
    }
    finalString.append(1, pre[0]);
    finalString.erase(finalString.length() - 1, 1);
    return finalString;
}
