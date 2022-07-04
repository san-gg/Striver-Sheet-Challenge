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
    recursion(arr, indx+1, sum, ds);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    K = k;
    //sort(arr.begin(), arr.end());
    recursion(arr, 0, 0, {});
    sort(ans.begin(), ans.end());
    return ans;
}