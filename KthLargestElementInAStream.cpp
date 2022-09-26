#include <bits/stdc++.h> 
class Kthlargest {
public:
    int kThLarge;
    vector<int> data;
    Kthlargest(int k, vector<int> &arr) : kThLarge(k), data(arr) {
        sort(data.begin(), data.end());
    }

    void add(int num) {
        auto itr = lower_bound(data.begin(), data.end(), num);
        data.insert(itr, num);
    }

    int getKthLargest() {
        return data[data.size() - kThLarge];
    }

};