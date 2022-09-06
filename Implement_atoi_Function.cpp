int atoi(string str) {
    int ans = 0;
    for(char c : str) {
        if(c >= '0' && c <= '9') {
            ans = ans * 10 + (c - '0');
        }
    }
    if(str.length() > 0 && str[0] == '-') {
        ans = -ans;
    }
    return ans;
}