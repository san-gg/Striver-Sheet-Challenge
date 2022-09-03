vector<int> findSpans(vector<int> &price) {
    vector<int> answer(price.size(), 1);
    vector<int> indx(price.size(), -1);
    int sz = price.size();
    for(int i = 0; i < sz; i++) {
        int x = i - 1;
        while(x >= 0) {
            if(price[x] > price[i]) {
                indx[i] = x;
                break;
            }
            answer[i] += answer[x];
            x = indx[x];
        }
    }
    return answer;
}