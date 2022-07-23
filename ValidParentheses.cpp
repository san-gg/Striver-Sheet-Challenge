#include <stack>
bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<pair<char, char>> st;
    for(char ch : expression) {
        if(ch == '{') st.push({'{', '}'});
        else if(ch == '(') st.push({'(', ')'});
        else if(ch == '[') st.push({'[', ']'});
        else if(!st.empty() && st.top().second == ch) st.pop();
        else return false;
    }
    if(st.empty()) return true;
    return false;
}