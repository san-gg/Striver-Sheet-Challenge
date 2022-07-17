int uniqueElement(vector<int> arr, int n)
{
    // O(n)
    int x = 0;
    for(int i = 1; i < n; i++) {
        if(arr[x] != arr[i] && (i - x) == 1) return arr[x];
        else if(arr[x] != arr[i]) x = i;
    }
    if(n - x == 1) return arr[x];
    return 0;
}
