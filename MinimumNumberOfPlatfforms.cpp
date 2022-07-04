int calculateMinPatforms(int at[], int dt[], int n) {
    int time[2361] = {0};
    int maxPlatforms = 1;
    for(int i = 0; i < n; i++) {
        ++time[at[i]];
        --time[dt[i]+1];
    }
    for(int i = 0; i < 2361; i++) {
        time[i+1] = time[i] + time[i+1];
        maxPlatforms = max(maxPlatforms, time[i]);
    }
    return maxPlatforms;
}