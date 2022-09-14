void getZarray(string &p, vector<int> &zarray) {
    int len = p.length();
    int left = 0;
    int right = 0; 
    for(int x = 1; x < len; x++) {
        if(x > right) {
            left = right = x;
            while(right < p.size() && p[right] == p[right-left])
                ++right;
            zarray[x] = right - left;
            --right;
        }
        else {
            int y = x - left;
            if(zarray[y] <= right - x) p[x] = p[y];
            else {
                // reset box
                left = x;
                while(right < p.size() && p[right] == p[right-left])
                    ++right;
                zarray[x] = right-left;
                --right;
            }
        }
    }
    return;
}

int zAlgorithm(string s, string p, int n, int m)
{
    string str = p + "$" + s;
    vector<int> zarray(str.length(), 0);
    getZarray(str, zarray);
    int count = 0;
    for(int i = 0; i < zarray.size(); i++) {
        if(zarray[i] == p.length()) ++count;
    }
    return count;
}