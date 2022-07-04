#include <algorithm>
vector<vector<int>> ans;
int K = 0;
void recursion(vector<int> &arr, int indx, int sum, vector<int> ds) {
    if(indx == arr.size()) {
        if(sum == K) {
            ans.push_back(ds);
        }
        return;
    }
    ds.push_back(arr[indx]);
    recursion(arr, indx+1, sum+arr[indx], ds);
    ds.pop_back();
    while(indx+1 < arr.size()) {
        if(arr[indx] != arr[indx+1]) break;
        ++indx;
    }
    recursion(arr, indx+1, sum, ds);
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
    ans.clear();
	K = target;
    sort(arr.begin(), arr.end());
    recursion(arr, 0, 0, {});
    sort(ans.begin(), ans.end());
    return ans;
}
