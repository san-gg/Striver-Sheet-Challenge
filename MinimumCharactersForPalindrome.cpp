int minCharsforPalindrome(string str) {
    int len = str.length();
    int x1 = 0;
    int x2 = len - 1;
    int count = 0;
    while(x1 < x2) {
        if(str[x1] != str[x2]) {
            x2 = x2 + x1;
            count = len - x2;
            x1 = 0;
            x2 -= 1;
        }
        else {
            x1 += 1;
            x2 -= 1;
        }
    }
    return count;
}