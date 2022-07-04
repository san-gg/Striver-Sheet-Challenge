#include <map>
#include <algorithm>
void recurssion(vector<int> &newNum, int indx, vector<int> subsets, vector<vector<int>> &ans) {
    if(indx == newNum.size()) {
        ans.push_back(subsets);
        return;
    }
    subsets.push_back(newNum[indx]);
    recurssion(newNum, indx+1, subsets, ans);
    subsets.pop_back();
    while(indx+1 < newNum.size()) {
        if(newNum[indx] != newNum[indx+1]) break;
        ++indx;
    }
    recurssion(newNum, indx+1, subsets, ans);
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    vector<vector<int>> answer;
    sort(arr.begin(), arr.end());
    recurssion(arr, 0, {}, answer);
    sort(answer.begin(), answer.end());
    return answer;
}