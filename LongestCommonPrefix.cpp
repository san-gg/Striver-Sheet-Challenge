string longestCommonPrefix(vector<string> &arr, int n)
{
    string prefix(arr[0]);
    for(string &str : arr) {
        int eq = 0;
        while(eq < prefix.length() && eq < str.length()) {
            if(prefix[eq] == str[eq]) ++eq;
            else break;
        }
        prefix = prefix.substr(0,eq);
        if(prefix.length() == 0) break;
    }
    return prefix;
}