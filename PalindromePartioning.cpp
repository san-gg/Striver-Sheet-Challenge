void recurs(vector<string> vstr, vector<vector<string>> &ans, string s) {
    int pos = 0;
    if(s.length() != 0) vstr.push_back(string(1, s[0]));
    if(s.length() == 1 || s.length() == 0) {
        ans.push_back(vstr);
        return;
    }
    string tmpStr = s.substr(1);
    recurs(vstr, ans, tmpStr);
    vstr.pop_back();
    int x = pos;
    ++pos;
    while(pos < s.length()) {
        if(s[x] == s[pos]) {
            int x1 = x;
            int x2 = pos;
            while(x1 < x2) {
                if(s[x1] != s[x2]) break;
                ++x1;
                --x2;
            }
            if(x1 >= x2) {
                vstr.push_back(s.substr(x,pos-x+1));
                tmpStr = s.substr(pos-x+1);
                recurs(vstr, ans, tmpStr);
                vstr.pop_back();
            }
        }
        ++pos;
    }
}

vector<vector<string>> partition(string &s) 
{
    vector<vector<string>> vvstr;
    vector<string> vstr;
    recurs(vstr, vvstr, s);
    return vvstr;
}