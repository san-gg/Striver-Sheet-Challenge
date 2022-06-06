#include <bits/stdc++.h> 
void sort012(int *arr, int n) {
    int no0 = 0;
    int no1 = 0;
    int no2 = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == 0) ++no0;
        else if(arr[i] == 1) ++no1;
        else if(arr[i] == 2) ++no2;
    }
    int pos = 0;
    while(pos < no0) arr[pos++] = 0;
    no1 += pos;
    while(pos < no1) arr[pos++] = 1;
    no2 += pos;
    while(pos < no2) arr[pos++] = 2;
}