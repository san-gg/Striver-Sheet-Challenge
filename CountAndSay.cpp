#include <string>
string writeAsYouSpeak(int n) 
{
    string answer = "1";
    if(n == 1) return answer;
    for(int i = 2; i <= n; i++) {
        string str;
        int n = 0;
        char prev = answer[0];
        for(char c : answer) {
            if(prev == c) ++n;
            else {
                str.append(to_string(n));
                str.append(1, prev);
                prev = c;
                n = 1;
            }
        }
        str.append(to_string(n));
        str.append(1, prev);
        answer = str;
    }
    return answer;
}