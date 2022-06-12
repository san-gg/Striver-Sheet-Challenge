#include <bits/stdc++.h>
void merge(vector<int> &arr,vector<int> &temp,int s,int mid,int e, int& c) {
    int i=s;
    int j=mid+1;
    int k=s;
    int x = i, y = j;
    while(x <= mid && y <= e) {
        if(arr[x] > (long)2 * arr[y]) {
            c += (mid - x + 1);
            ++y;
        }else {
            ++x;
        }
    }
    while(i<=mid && j<=e){
        if(arr[i]<=arr[j]){
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }
    while(i<=mid){
        temp[k++] = arr[i++];
    }
    while(j<=e){
        temp[k++] = arr[j++];
    }
    for(int i=s;i<=e;i++)
        arr[i]=temp[i];
}
void mergesort(vector<int> &arr,vector<int> &temp,int s,int e,int& x) {
    if(s>=e) return;
    int mid = s+(e-s)/2;
    mergesort(arr,temp,s,mid,x);
    mergesort(arr,temp,mid+1,e,x);
    merge(arr,temp,s,mid,e,x);
}
int reversePairs(vector<int> &arr, int n) {
    int count = 0;
    vector<int> tmp(n, 0);
    mergesort(arr, tmp, 0, n - 1, count);
    return count;
} 