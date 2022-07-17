#define ll long long
ll perDayTime(ll val, int n, int m, vector<int> &time) {
    int days = 1;
    ll maxVal = 0;
    ll sum = 0;
    for(int i = 0; i < m; i++) {
        if(days != n && sum + time[i] > val) {
            maxVal = max(sum, maxVal);
            sum = 0;
            ++days;
        }
        sum += time[i];
    }
    maxVal = max(maxVal, sum);
    return maxVal;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{
    ll high = 0;
    ll low = 0;
    ll answer = 0;
    for(int x : time) high += x;
    answer = high;
    while(low <= high) {
        ll mid = low + (high - low) / 2;
        ll mtime = perDayTime(mid, n, m, time);
        answer = min(answer, mtime);
        if(mtime <= mid) high = mid - 1;
        else if(mtime > mid) low = mid + 1;
    }
    return answer;
}