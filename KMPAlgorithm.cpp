void buildKMP(string &p, vector<int> &kmpArray) {
    int x1 = 0;
    int x2 = 1;
    while(x2 < p.length()) {
        if(p[x1] == p[x2]) {
            kmpArray[x2] = x1 + 1;
            x1 += 1;
            x2 += 1;
        } else {
            if(x1 - 1 >= 0) x1 = kmpArray[x1 - 1];
            else x2 += 1;
        }
    }
    return;
}

bool findPattern(string p, string s)
{
    vector<int> kmpArray(p.length(), 0);
    buildKMP(p, kmpArray);
    int x1 = 0, x2 = 0;
    while(x1 < s.length()) {
        if(s[x1] == p[x2]) {
            ++x2;
            ++x1;
        }
        else {
            if(x2 - 1 >= 0) x2 = kmpArray[x2 - 1];
            else ++x1;
        }
        if(x2 == p.length()) return true;
    }
    return false;
}