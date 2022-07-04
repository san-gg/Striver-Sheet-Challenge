#include <algorithm>
void recurssion(vector<int> &num, int i, int sum, vector<int> &ans) {
    if(i == num.size()) {
        ans.push_back(sum);
        return;
    }
    recurssion(num, i+1, sum+num[i], ans);
    recurssion(num, i+1, sum, ans);
}
vector<int> subsetSum(vector<int> &num)
{
    vector<int> ans;
    recurssion(num, 0, 0, ans);
    sort(ans.begin(), ans.end());
    // Write your code here.
    return ans;
}