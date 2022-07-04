int removeDuplicates(vector<int> &arr, int n) {
    int ans = 1;
    for(int i = 1; i < n; i++) {
        ans += 1;
        if(arr[i - 1] >= arr[i]) {
            int x = i - 1;
            while(x >= 0) {
                if(arr[x] == arr[x + 1]) {
                    ans -= 1;
                    break;
                }
                if(arr[x] < arr[x+1])
                    break;
                swap(arr[x], arr[x+1]);
                x -= 1;
            }
        }
    }
    return ans;
}