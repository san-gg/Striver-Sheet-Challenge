string removeZero(string &x) {
    int len = x.length() - 1;
    string ret(x);
    while(len >= 1) {
        if(x[len] != '0' && x[len] != '.') {
            while(len < x.length()) {
                if(x[len] == '.') break;
                len += 1;
            }
            len -= 1;
            break;
        }
        --len;
    }
    ret = x.substr(0, len+1);
    return ret;
}
int compareVersions(string a, string b) 
{
    int answer = 2;
    a = removeZero(a);
    b = removeZero(b);
    a.append(1,'.');
    b.append(1,'.');
    int x1 = 0;
    int x2 = 0;
    while(x1 < a.length() && x2 < b.length()) {
        if(a[x1] != '.' && a[x1] > b[x2] && answer == 2) answer = 1;
        else if(b[x2] != '.' && a[x1] < b[x2] && answer == 2) answer = -1;
        else if(a[x1] == '.' && b[x2] == '.') {
            if(answer != 2) return answer;
        }
        else if(a[x1] == '.') return -1;
        else if(b[x2] == '.') return 1;
        ++x1;
        ++x2;
    }
    if(x1 == a.length() && x2 != b.length()) return -1;
    else if(x1 != a.length() && x2 == b.length()) return 1;

    return 0;
}