#include <vector>
string reverseString(string str)
{
    vector<string> arr;
    int pos1 = 0;
    int pos2 = 0;
    while(pos1 < str.length()) {
        pos1 = str.find_first_not_of(' ', pos1);
        if(pos1 == -1) break;
        pos2 = str.find_first_of(' ', pos1);
        if(pos2 == -1) pos2 = str.length();
        arr.push_back(str.substr(pos1, pos2-pos1));
        pos1 = pos2;
    }
    string ans;
    for(int i = arr.size()-1; i>=0; i--) {
        ans += arr[i];
        ans += " ";
    }
    ans = ans.substr(0, ans.length()-1);
    return ans;
}