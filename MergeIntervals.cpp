#include <bits/stdc++.h> 
/*
//Debug
cout << answer[indx][0] << " " << answer[indx][1] << endl;
        cout << intervals[x][0] << " " << intervals[x][1] << endl;
        cout << "=============\n";
*/
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    vector<vector<int>> answer;
    int indx = 0;
    int sz = intervals.size();
    answer.push_back(vector<int>(2));
    sort(intervals.begin(), intervals.end());
    answer[0][0] = intervals[0][0];
    answer[0][1] = intervals[0][1];
    for(int x = 1; x < sz; ++x) {
        if(answer[indx][1] >= intervals[x][1]) continue;
        else if(intervals[x][0] <= answer[indx][1]) {
            answer[indx][1] = intervals[x][1];
            continue;
        }
        indx += 1;
        answer.push_back(vector<int>(2));
        answer[indx][0] = intervals[x][0];
        answer[indx][1] = intervals[x][1];
    }
    return answer;
}
