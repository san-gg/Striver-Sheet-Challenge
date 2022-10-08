#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> notLIS; 
    notLIS.push_back(arr[0]);
    for(int index=1; index<n; index++)
    {
        if(arr[index] > notLIS.back())
        {
            notLIS.push_back(arr[index]);
        }
        else
        {
            int smallerIndex = lower_bound(notLIS.begin(), notLIS.end(), arr[index]) - notLIS.begin();
            notLIS.at(smallerIndex) = arr[index];
        }
    }
    
    return notLIS.size();
}
