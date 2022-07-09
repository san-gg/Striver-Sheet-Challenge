void recurs(int indx, string str1, string str2, vector<string> &ans) {
    if(str2.length() == 0) {
        ans.push_back(str1);
    }
    for(int i = 0; i < str2.length(); ++i) {
        str1[indx] = str2[i];
        str2.erase(i,1);
        recurs(indx+1, str1, str2, ans);
        str2.insert(0, 1, str1[indx]);
    }
}
vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string> vstr;
    string build(s.length(), '\0');
    recurs(0, build, s, vstr);
    return vstr;
}